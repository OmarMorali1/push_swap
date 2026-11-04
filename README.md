
*This project has been created as part of the 42 curriculum by atahlawi, ommorali.*

# push_swap

`push_swap` sorts a stack of integers using a restricted instruction set and two stacks (`a` and `b`), printing the shortest sequence of instructions it can find. A companion `checker` program reads an instruction list and verifies whether it sorts the stack.

---
## Description

### Table of contents

1. [Team and contributions](#team-and-contributions)
2. [Build](#build)
3. [Usage](#usage)
4. [Instruction set](#instruction-set)
5. [Architecture](#architecture)
6. [Sorting strategies](#sorting-strategies)
7. [Adaptive mode and the disorder metric](#adaptive-mode-and-the-disorder-metric)
8. [Benchmark mode](#benchmark-mode)
9. [Checker](#checker)
10. [Error handling](#error-handling)
11. [Performance](#performance)
12. [Testing](#testing)
13. [File map](#file-map)
14. [Resources](#resources)
15. [AI usage](#ai-usage)

---

### Team and contributions

| Member | Main responsibilities |
|---|---|
| **atahlawi** | Simple sort (selection), medium sort (chunk), bonus (`checker` and `get_next_line`), miscellaneous tasks |
| **ommorali** | Complex sort (Turk-style cost-based insertion), benchmark mode, Norm compliance, miscellaneous tasks |

---
## Instructions

### Build

```sh
make          # builds push_swap and checker
make bonus    # builds checker only
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```

Compiled with `cc -Wall -Wextra -Werror`. No external libraries are used; the small libft subset (`ft_split`, `ft_calloc`, `ft_memset`, `ft_strncmp`) is included in the sources.

---

### Usage

```sh
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] <numbers...>
```

Numbers can be given as separate arguments, as one quoted string, or mixed:

```sh
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap "5 4" 3 "2 1"
```

| Flag | Meaning |
|---|---|
| `--simple` | Force the selection sort (O(n²)) |
| `--medium` | Force the chunk sort (O(n√n)) |
| `--complex` | Force the cost-based insertion sort (O(n log n) class) |
| `--adaptive` | Choose a strategy from the input's disorder (default when no strategy flag is given) |
| `--bench` | Print statistics to **stderr** after sorting |

Rules: at most one strategy flag is allowed; `--bench` may appear before or after it; flags must come before the numbers.

Instructions are written to **stdout**, errors and benchmark output to **stderr**.

Typical pipeline with the checker:

```sh
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l          # number of instructions
```

---

### operations set

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | Swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | Reverse rotate `a` / `b` / both (last element becomes first) |

Implementation notes:

- The operation functions (`swap_push.c`, `stack_rotate.c`, `stack_reverse_rotate.c`) are shared by `push_swap` and `checker`.
- `sa`, `sb`, `ra`, `rb`, `rra`, `rrb` take an explicit `print` flag. `ss`, `pa`, `pb`, `rr`, `rrr` print **only when a `t_bench` pointer is supplied**. `push_swap` always passes one; the checker passes `NULL`, so it executes silently.
- `ss`, `rr` and `rrr` act on whichever stack has enough elements, as the subject requires.

---

### Architecture

The stack is a singly linked list:

```c
typedef struct s_stack
{
	int				value;       // the integer
	int				index;       // rank in sorted order (0 = smallest)
	int				pos;         // current position in its stack
	int				target_pos;  // position in `a` where this node must land
	int				cost_a;      // signed rotations needed in `a`
	int				cost_b;      // signed rotations needed in `b`
	int				total_cost;  // moves needed, counting rr/rrr savings
	struct s_stack	*next;
}	t_stack;
```

`t_bench` holds one counter per instruction, an `active` flag, and the disorder value computed before sorting.

Flow of `main`:

1. Parse flags (`parse_flags`).
2. Parse and validate numbers into stack `a` (`fill_stack_a`).
3. If `a` is not already sorted, compute the disorder and dispatch to a strategy.
4. If `--bench` was given, print the statistics to stderr.
5. Free both stacks.

---

### Sorting strategies

### Small cases (all strategies)

- 2 elements: at most one `sa`.
- 3 elements: `sort_three`, which handles all six permutations in at most 2 instructions.
- 4–5 elements: `small_sort` pushes the smallest elements to `b` (using the shorter rotation direction), runs `sort_three` on the remaining three, then pushes back. Worst case over all 120 permutations of 5 numbers is **10 instructions**.

### Simple: selection sort, O(n²) (`selection_sort.c`)

Repeatedly bring the minimum of `a` to the top with `ra` or `rra` (whichever is shorter) and push it to `b`, until three elements remain. Sort those three, then `pa` everything back; since the minima were pushed in ascending order, `b` pops in the right order.

### Medium: chunk sort, O(n√n) (`chunk_sort.c`)

1. Compute the rank (`index`) of every element.
2. Chunk size = ⌊√n⌋ (computed with a binary search, no `math.h`).
3. Scan `a`, with `cnt` = number of elements already pushed:
   - `index <= cnt`: push to `b` and rotate `b`, so small values sink to the bottom.
   - `index <= cnt + chunk`: push to `b` and leave on top.
   - otherwise: `ra`.
4. Pull everything back by repeatedly locating the maximum of `b`, rotating it to the top (shorter direction), and pushing it to `a`.

### Complex: cost-based insertion (`hard1.c`, `hard2.c`, `hard3.c`)

1. Compute ranks.
2. Push everything except three elements to `b`; sort the three with `sort_three`.
3. Loop while `b` is not empty:
   - For every node in `b`, find its **target** in `a`: the node with the smallest rank greater than it (or the minimum if none exists), so that `a` stays cyclically sorted.
   - Compute `cost_b` and `cost_a` as signed rotation counts (positive = rotate, negative = reverse rotate, choosing the shorter direction in each stack).
   - Compute `total_cost`: if both costs have the same sign, the cost is `max(|a|, |b|)` because `rr` / `rrr` do both at once; otherwise it is `|a| + |b|`.
   - Execute the cheapest node's moves (`rotate_both` first, then the remainder) and `pa`.
4. Rotate `a` so the minimum is on top.

Positions of both stacks are recomputed before each round (`set_positions`), since each `pa` shifts everything.

---

## Adaptive mode and the disorder metric

```
disorder = mistakes / total_pairs
```

where a *mistake* is a pair `(i, j)` with `i < j` and `value[i] > value[j]`. It is `0.0` for a sorted stack and `1.0` for a reversed one.

| Disorder | Strategy chosen | Class |
|---|---|---|
| `< 0.2` | selection sort | O(n²) |
| `0.2 – 0.5` | chunk sort | O(n√n) |
| `≥ 0.5` | cost-based insertion | O(n log n) |

The disorder is measured **before** sorting and stored in the `t_bench` struct so that `--bench` reports the original input's disorder, not that of the sorted result.

---

### Benchmark mode

`--bench` prints to **stderr**, so stdout still contains only instructions:

```
[bench] disorder: 100.00%
[bench] strategy: Simple / O(n^2)
[bench] total_ops: 8
[bench] sa: 1 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 0 rb: 0 rr: 0 rra: 3 rrb: 0 rrr: 0
```

Output uses small custom helpers (`put_str_fd`, `put_nbr_fd`, `put_double_fd` in `bench_tools.c`), so no `printf` is needed. In adaptive mode the strategy line reports which class was actually selected (for example `Adaptive / O(n log n)`).

```sh
./push_swap --bench --simple 5 4 3 2 1 2>/dev/null          # instructions only
./push_swap --bench --simple 5 4 3 2 1 2>bench.txt >/dev/null && cat bench.txt
```

---

### Checker

```sh
./checker <numbers...>
```

Reads instructions from stdin, one per line (until EOF / `Ctrl+D`), applies them to the stack and prints:

| Output | Stream | Meaning |
|---|---|---|
| `OK` | stdout | `a` sorted and `b` empty |
| `KO` | stdout | otherwise |
| `Error` | stderr | invalid arguments, or an unknown / malformed instruction |

Details:

- Lines are read with `get_next_line` and matched **exactly**, including the trailing newline. Leading/trailing spaces, a missing newline at EOF or an unknown name all produce `Error`.
- With no arguments, the checker prints nothing and exits.
- The checker shares the parsing and operation code with `push_swap`.

---

### Error handling

Both programs print `Error\n` on stderr and exit with status 1 for:

- non-numeric tokens (anything other than an optional sign followed by digits);
- duplicates (compared by value, so `1 +1` is a duplicate);
- values outside the `int` range (`ft_atoll` stops early on very long digit strings so they can't wrap around);
- empty-string arguments, unknown flags, or two strategy flags;
- flags with no numbers after them.

With no arguments at all, both programs print nothing and return 0. Already sorted input produces no output.

All allocations are freed on every path (verified with AddressSanitizer).

---

### Performance

Measured on random permutations (checker output `OK` in every run):

| Input | Mode | Min | Avg | Max |
|---|---|---|---|---|
| 5 numbers | any | | | 10 (all 120 permutations) |
| 100 numbers | adaptive | 532 | 582 | 650 |
| 100 numbers | `--medium` | 560 | 596 | 632 |
| 100 numbers | `--complex` | 523 | 583 | 654 |
| 100 numbers | `--simple` | 1208 | 1421 | 1584 |
| 500 numbers | adaptive | 4960 | 5222 | 5352 |
| 500 numbers | `--medium` | 5153 | 5276 | 5469 |
| 500 numbers | `--complex` | 4912 | 5184 | 5459 |

Reversed inputs: 500 numbers take 1493 instructions with `--complex` / adaptive (and 7131 with `--medium`).

---

### Testing

```sh
# Identity: must print nothing
./push_swap 42; ./push_swap 2 3; ./push_swap 0 1 2 3

# Small
ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG

# Errors
./push_swap a 1; ./push_swap 1 1; ./push_swap 1 2147483648

# Checker
./checker 0 1 2 </dev/null                                   # OK
printf 'pb\nra\npb\nra\nsa\nra\npa\npa\n' | ./checker 0 9 1 8 2   # OK
printf 'sa\npb\nrrr\n' | ./checker 0 9 1 8 2 7 3 6 4 5       # KO

# Large
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

Memory checking:

```sh
cc -g -fsanitize=address,undefined *.c -o ps_asan   # (exclude checker.c)
```

---

## Resources

- The 42 `push_swap` subject (instruction set, flags, evaluation checklist).
- The 42 Norm (Norminette rules) for coding-style requirements.
- Linux man pages: `read(2)`, `write(2)`, `malloc(3)`, `free(3)`.
- Articles and write-ups on the *Turk algorithm* (cost-based insertion between two stacks) and on chunk-based sorting for `push_swap`.
- General references for the algorithms used: selection sort, and the idea of ranking values (index normalisation) before sorting.
- Tools used for verification: `shuf` for random inputs, `valgrind` / AddressSanitizer for memory checks, and the provided `checker_linux`.

> Add the exact links or articles you used here before submitting.

---

## AI usage

AI (Anthropic's Claude) was used as a **review and assistance tool**, not as a replacement for understanding the code. The design of the strategies, the disorder metric and the project structure were done by the team.

What the AI was used for:

- **Code review against the evaluation checklist:** reading all source files and listing bugs that would fail evaluation (for example the wrong `sort_three` cases, `pa`/`pb`/`rr`/`ss` printing during `checker` runs, indices not computed before sorting, and the disorder being measured after sorting in `--bench`).
- **Bug fixes:** proposing and applying fixes for those bugs, then re-testing them.
- **Norm-style cleanup:** removing duplicate headers, replacing ternaries and compound literals, splitting functions that were too long or files with too many functions, and fixing spacing and alignment.
- **Test scripts:** generating the randomized and edge-case tests used for the results in the [Performance](#performance) section, including AddressSanitizer runs.
- **Documentation:** drafting this README.

What was done by the team:

- Writing and designing the original code, the three sorting strategies, the benchmark mode and the checker.
- Reviewing every AI-suggested change, rebuilding and re-running the tests, and running Norminette and the provided `checker_linux` on the final version.
- Making the final decisions on what to keep.

Every team member is expected to be able to explain and defend all code in this repository.


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_bench
{
	int		active;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disord;
}		t_bench;

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

void		sa(t_stack **a, t_bench *bench, int print);
void		sb(t_stack **b, t_bench *bench, int print);
void		ss(t_stack **a, t_stack **b, t_bench *bench);
void		pa(t_stack **a, t_stack **b, t_bench *bench);
void		pb(t_stack **a, t_stack **b, t_bench *bench);

void		ra(t_stack **a, t_bench *bench, int print);
void		rb(t_stack **b, t_bench *bench, int print);
void		rr(t_stack **a, t_stack **b, t_bench *bench);
void		rra(t_stack **a, t_bench *bench, int print);
void		rrb(t_stack **b, t_bench *bench, int print);
void		rrr(t_stack **a, t_stack **b, t_bench *bench);

int			valid_num(char *str);
int			has_duplicate(t_stack *a, int val);
long long	ft_atoll(char *str);
int			parse_flags(int argc, char **argv, t_bench *bench, int *method);
int			stack_len(t_stack *stack);
int			ft_abs(int n);
int			is_sorted(t_stack *a);

void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t n, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_split(char **str);
char		**ft_split(char const *s, char c);

void		free_stack(t_stack **a);
void		stack_add_back(t_stack **a, t_stack *new);
t_stack		*new_node(int val);
int			fill_stack_a(t_stack **a, char **argv, int start);

double		disorder(t_stack *a);
void		index_stack(t_stack *a);
void		selection_sort(t_stack **a, t_stack **b, t_bench *bench);
void		small_sort(t_stack **a, t_stack **b, t_bench *bench);
void		chunk_sort(t_stack **a, t_stack **b, t_bench *bench);
void		turk_sort(t_stack **a, t_stack **b, t_bench *bench);
void		sort_three(t_stack **a, t_bench *bench);
void		calculate_and_set_costs(t_stack *a, t_stack *b);
void		push_back_to_a(t_stack **a, t_stack **b, t_bench *bench);

void		print_bench(t_bench *b, int method);
void		put_str_fd(char *s, int fd);
void		put_nbr_fd(int n, int fd);
void		put_double_fd(double n, int fd);

char		*get_next_line(int fd);
char		*read_file(char *str, int fd);
char		*get_line(char *str);
char		*new_str(char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*copy_str(char *str, int i);
char		*check_str(char *str);
size_t		ft_strlen(const char *s);
int			execute_operation(t_stack **a, t_stack **b, char *op);

#endif

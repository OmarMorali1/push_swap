/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:32 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:13:47 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}		t_stack;

typedef struct s_bench
{
	int	active;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_bench;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		disorder(t_stack *a);
int			buket_count(int len);
int			get_max_pos(t_stack *b);
void		buket_sort(t_stack **a, t_bench *b);
void		sa(t_stack **a, t_bench *b);
void		sb(t_stack **a, t_bench *b);
void		ss(t_stack **a, t_stack **b, t_bench *bench);
void		pa(t_stack **a, t_stack **b, t_bench *bench);
void		pb(t_stack **a, t_stack **b, t_bench *bench);
void		ra(t_stack **a, t_bench *b);
void		rb(t_stack **a, t_bench *b);
void		rr(t_stack **a, t_stack **b, t_bench *bench);
void		rra(t_stack **a, t_bench *b);
void		rrb(t_stack **a, t_bench *b);
void		rrr(t_stack **a, t_stack **b, t_bench *bench);
t_stack		*stack_new(int x);
void		stack_add_back(t_stack **stack, t_stack *new);
int			duplicate(t_stack *a);
void		free_stack(t_stack **a);
int			valid_num(char *str);
long long	ft_atoll(char *str);
int			is_int(char *str);
char		**get_num(int argc, char **argv);
void		freesplit(char **str);
int			add_number(t_stack **a, char *str);
int			is_sort(t_stack *a);
void		index_stack(t_stack *a);
void		easy_sort(t_stack **a, t_bench *b);
void		hard_radix_sort(t_stack **a, int size, t_bench *b);
int			stack_len(t_stack *stack);
void		*ft_calloc(size_t n, size_t size);
char		**ft_split(char const *s, char c);
void		print_bench(t_bench *b, double disord, int method);
int			parse_args(int argc, char **argv, int *start, t_bench *bench);
int			get_method(char *str);
void		put_double_fd(double n, int fd);
void		put_nbr_fd(int n, int fd);
void		put_str_fd(char *s, int fd);

#endif
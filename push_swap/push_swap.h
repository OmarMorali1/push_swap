/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:41:54 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/26 13:51:51 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
t_stack			*stack_new(int x);
void			stack_add_back(t_stack **stack, t_stack *new);
int				duplicate(t_stack *a);
void			free_stack(t_stack **a);
int				valid_num(char *str);
long long		ft_atoll(char *str);
int				is_int(char *str);
char			**get_num(int argc, char **argv);
void			freesplit(char **str);
int				add_number(t_stack **a, char *str);
int				is_sort(t_stack *a);
int				get_index(t_stack *a, int x);
void			index_stack(t_stack *a);
void			easy_sort(t_stack **a, t_stack **b);
void			hard_radix_sort(t_stack **a, t_stack **b, int size);
int				stack_len(t_stack *stack);
void			*ft_calloc(size_t n, size_t size);
char			**ft_split(char const *s, char c);

#endif

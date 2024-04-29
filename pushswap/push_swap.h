/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:19:32 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/29 20:31:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_list t_list;

typedef struct s_list
{
	int 	data;
	t_list	*next;
	t_list	*prev;
} 				t_list;

int 	partition(t_list **stack, int low, int high);
void 	part_sort(t_list **stack, int low, int high);
void 	last_sort(t_list **stack_a, t_list **stack_b);
void 	sort_two_stacks(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
void	add(t_list **head, int value);
void	ft_free(char **s);
void	ft_free_stack(t_list **stack);
int		arr_len(char **input);
int		check_doubles(char **input, int x);
void	fill_stack(int ac, char **av, t_list **head);
int		ft_find(char *str, int c);
int		valid_arg(char **av);
int		locate(t_list *stack, int data);
int		rot_until(t_list **stack, int data);
int		rot_double(t_list **stack_a, t_list **stack_b, int data_a, int data_b);
void	sort_three(t_list **stack);
void	sort_three_b(t_list **stack);
void	sort_three_a(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);
void	sort_more(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		stack_size(t_list *stack);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
void	pushback(t_list **stack_a, t_list **stack_b);
void	show(t_list *stack);

/*PUSWSWAP LIBRARY*/
void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	rot(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rev_rot(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif

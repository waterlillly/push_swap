/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:19:32 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/06 22:34:43 by lbaumeis         ###   ########.fr       */
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

/*SORTING*/
int		sort(t_list **stack_a, t_list **stack_b);
int		sort_three(t_list **stack);
int		sort_three_a(t_list **stack);
int		sort_three_b(t_list **stack);
int		sort_five(t_list **stack_a, t_list **stack_b);
int		sort_to_b(t_list **stack_a, t_list **stack_b);
int		back_to_a(t_list **stack_a, t_list **stack_b);
int		sort_both(t_list **stack_a, t_list **stack_b);

/*CHECKING*/
int		is_sorted(t_list *stack);
int		arr_len(char **input);
int		check_doubles(char **input, int x);
int		stack_size(t_list *stack);
int		ft_find(char *str, int c);
int		valid_arg(char **av);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		locate(t_list *stack, int data);
int		rot_until(t_list **stack, int data);
int		rot_double(t_list **stack_a, t_list **stack_b, int data_a, int data_b);
void	show(t_list *stack);

/*STACK*/
void	add(t_list **head, int value);
void	fill_stack(int ac, char **av, t_list **head);
void	ft_free(char **s);
void	ft_free_stack(t_list **stack);

/*PUSHSWAP OPERATIONS*/
void	swap(t_list **stack);
int		sa(t_list **a);
int		sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
void	rot(t_list **stack);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
void	rev_rot(t_list **stack);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

#endif

/*SORT
void	sort_more(t_list **stack_a, t_list **stack_b);
void	pushback(t_list **stack_a, t_list **stack_b);
void 	bubble(t_list **stack_a, t_list **stack_b);
void	list_sort(t_list **stack_a, t_list **stack_b);
void	sort_list(t_list **stack_a, t_list **stack_b);
void	parse_stack(t_list **stack_a, t_list **stack_b);
void 	bubbleSort(t_list **head_ref);
void 	selectionSort(t_list **head_ref);
void 	sortedInsert(t_list **head_ref, t_list *new_node);
void 	insertionSort(t_list **head_ref);
int 	partition(t_list **stack, int low, int high);
void 	part_sort(t_list **stack, int low, int high);
void 	last_sort(t_list **stack_a, t_list **stack_b);
*/
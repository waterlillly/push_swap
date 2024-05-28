/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:19:32 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 15:14:25 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_list t_list;

typedef struct s_list
{
	int 	data;
	int		index;
	int		price;
	int		cheapest;
	t_list	*target;
	t_list	*next;
	t_list	*prev;
} 				t_list;

/*PS*/
int		rot_both_top(t_list **a, t_list **b, int loc_a, int loc_b);
int		rot_both_bot(t_list **a, t_list **b, int loc_a, int loc_b);
int		rot_else_a(t_list **a, int loc_a);
int		rot_else_b(t_list **b, int loc_b);
int		rot_else(t_list **a, t_list **b, int loc_a, int loc_b);
int		rot_cheapest(t_list **stack_a, t_list **stack_b);

/*UPDATE*/
void	update_index(t_list **stack);
void	update_index_target(t_list **stack);
void	update_cheapest(t_list **stack);
int		locate_cheapest(t_list *s);

/*UPDATE_A*/
void 	get_target_a(t_list **stack_a, t_list **stack_b);
void	update_price_a(t_list *a, t_list *b);
void	update(t_list **a, t_list **b);

/*UPDATE_B*/
void 	get_target_b(t_list **stack_a, t_list **stack_b);
void	update_price_b(t_list *a, t_list *b_);
void	final(t_list **a, t_list **b);

/*SORTING*/
int		how_to_sort(t_list **a, t_list **b);
int		a_to_b(t_list **a, t_list **b);
int		b_to_a(t_list **a, t_list **b);
int		sort_five_max(t_list **stack_a, t_list **stack_b);
int		sort_three(t_list **stack);
int		sort_three_a(t_list **stack);
int		sort_three_b(t_list **stack);
int		sort_five(t_list **stack_a, t_list **stack_b);
int		find_max(t_list *s);
int		find_min(t_list *s);
int		find_mid(t_list *s);
int		do_the_sort(t_list **stack_a, t_list **stack_b);
int		swapping(t_list **stack_a, t_list **stack_b);
int		continuing(t_list **stack_a, t_list **stack_b);

/*CHECKING*/
int		is_sorted(t_list *stack);
int		arr_len(char **input);
int		check_doubles(char **input, int x);
int		stack_size(t_list *stack);
int		ft_find(char *str, int c);
int		valid_arg(char **av);
int		locate(t_list *s, int data);
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
int		ss(t_list **a, t_list **b);
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

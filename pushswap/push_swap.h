/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:19:32 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 12:16:45 by lbaumeis         ###   ########.fr       */
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

/*STACK*/
void	add(t_list **head, int value);
void	fill_stack(int ac, char **av, t_list **head);
void	ft_free(char **s);
void	ft_free_stack(t_list **stack);

/*ROTATE*/
void	rot_else_a(t_list **a, int loc_a);
void	rot_else_b(t_list **b, int loc_b);
void	rot_else(t_list **a, t_list **b, int loc_a, int loc_b);
void	rot_cheapest(t_list **stack_a, t_list **stack_b);
void	rot_until(t_list **stack, int data);

/*ROTATE_BOTH*/
void	rot_both_top(t_list **a, t_list **b, int loc_a, int loc_b);
void	rot_both_bot(t_list **a, t_list **b, int loc_a, int loc_b);
void	rot_double(t_list **stack_a, t_list **stack_b, int data_a, int data_b);
void	rot_double_2(t_list **stack_a, t_list **stack_b, int loc_a, int loc_b);

/*UPDATE*/
void	update_index(t_list **stack);
void	update_cheapest(t_list **stack);
int		locate_cheapest(t_list *s);

/*UPDATE_A*/
void 	get_target_a(t_list **stack_a, t_list **stack_b);
void	get_target_a_2(t_list **stack_a, t_list **stack_b);
void	update_price_a(t_list *a, t_list *b);
void	update_price_a_2(t_list *a, t_list *b, int size_a, int size_b);
void	update(t_list **a, t_list **b);

/*UPDATE_B*/
void 	get_target_b(t_list **stack_a, t_list **stack_b);
void	get_target_b_2(t_list **stack_a, t_list **stack_b);
void	update_price_b(t_list *a, t_list *b_);
void	update_price_b_2(t_list *a, t_list *b, int size_a, int size_b);
void	final(t_list **a, t_list **b);

/*SORTING*/
void	sort(t_list **a, t_list **b);
void	a_to_b(t_list **a, t_list **b);
void	b_to_a(t_list **a, t_list **b);

/*SORT_FIVE*/
void	sort_five_max(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);

/*SORT_THREE*/
void	sort_three(t_list **stack);
void	sort_three_a(t_list **stack);
void	sort_three_b(t_list **stack);

/*FIND*/
int		find_max(t_list *s);
int		find_min(t_list *s);
int		find_mid(t_list *s);
int		locate(t_list *s, int data);

/*CHECK_SORT*/
void	error(void);
int		is_sorted(t_list *stack);

/*CHECK_STACK*/
int		arr_len(char **input);
int		check_doubles(char **input, int x);
int		stack_size(t_list *stack);
int		ft_find(char *str, int c);
int		valid_arg(char **av);

/*PUSHSWAP OPERATIONS*/
/*SWAP*/
void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

/*PUSH*/
void	push(t_list **src, t_list **dst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

/*ROT*/
void	rot(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

/*REV_ROT*/
void	rev_rot(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif

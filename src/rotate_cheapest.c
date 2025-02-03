/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:03:10 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		loc_a;
	int		loc_b;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	loc_a = locate_cheapest(a);
	loc_b = locate_cheapest(a->target);
	if (loc_a == -1 || loc_b == -1)
		return ;
	else if (a && b && (loc_a <= stack_size(a) / 2)
		&& (loc_b <= stack_size(b) / 2))
		rot_both_top(&a, &b, loc_a, loc_b);
	else if (a && b && (loc_a > stack_size(a) / 2)
		&& (loc_b > stack_size(b) / 2))
		rot_both_bot(&a, &b, loc_a, loc_b);
	else
		rot_else(&a, &b, loc_a, loc_b);
	*stack_a = a;
	*stack_b = b;
}

void	rot_cheap(t_list **stack_a, t_list **stack_b)
{
	t_list	*loc_a;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	loc_a = loc_cheapest(a);
	if (!loc_a)
		return ;
	rot_until(&a, loc_a->data);
	rot_until_b(&b, loc_a->target->data);
	*stack_a = a;
	*stack_b = b;
}

void	rot_cheap_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*loc_b;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	loc_b = loc_cheapest(b);
	if (!loc_b)
		return ;
	rot_until_b(&b, loc_b->data);
	rot_until(&a, loc_b->target->data);
	*stack_a = a;
	*stack_b = b;
}

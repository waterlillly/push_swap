/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:08:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_both_top(t_list **a, t_list **b, int loc_a, int loc_b)
{
	while (loc_a >= 0 && loc_b >= 0)
	{
		rr(a, b);
		loc_a--;
		loc_b--;
	}
	while (loc_a > 0)
	{
		ra(a);
		loc_a--;
	}
	while (loc_b > 0)
	{
		rb(b);
		loc_b--;
	}
}

void	rot_both_bot(t_list **a, t_list **b, int loc_a, int loc_b)
{
	while (loc_a <= stack_size(*a) && loc_b <= stack_size(*b))
	{
		rrr(a, b);
		loc_a++;
		loc_b++;
	}
	while (loc_a < stack_size(*a))
	{
		rra(a);
		loc_a++;
	}
	while (loc_b < stack_size(*b))
	{
		rrb(b);
		loc_b++;
	}
}

void	rot_else_one(t_list **stack_a, t_list **stack_b, int loc_a, int loc_b)
{
	while (loc_a > 0)
	{
		ra(stack_a);
		loc_a--;
	}
	while (loc_b < stack_size(*stack_b))
	{
		rrb(stack_b);
		loc_b++;
	}
}

void	rot_else_two(t_list **stack_a, t_list **stack_b, int loc_a, int loc_b)
{
	while (loc_a < stack_size(*stack_a))
	{
		rra(stack_a);
		loc_a++;
	}
	while (loc_b >= 0)
	{
		rb(stack_b);
		loc_b--;
	}
}

void	rot_both(t_list **stack_a, t_list **stack_b)
{
	int		loc_a;
	int		loc_b;

	loc_a = locate_cheapest(*stack_a);
	loc_b = locate_cheapest(*stack_b);
	if (loc_a == -1 || loc_b == -1)
		return ;
	if ((loc_a <= stack_size(*stack_a) / 2)
		&& (loc_b <= stack_size(*stack_b) / 2))
		rot_both_top(stack_a, stack_b, loc_a, loc_b);
	else if ((loc_a > stack_size(*stack_a) / 2)
		&& (loc_b > stack_size(*stack_b) / 2))
		rot_both_bot(stack_a, stack_b, loc_a, loc_b);
	else if ((loc_a <= stack_size(*stack_a) / 2)
		&& (loc_b > stack_size(*stack_b) / 2))
		rot_else_one(stack_a, stack_b, loc_a, loc_b);
	else if ((loc_a > stack_size(*stack_a) / 2)
		&& (loc_b <= stack_size(*stack_b) / 2))
		rot_else_two(stack_a, stack_b, loc_a, loc_b);
}

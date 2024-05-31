/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/31 23:08:18 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_else_a(t_list **a, int loc_a)
{
	if (*a && loc_a <= stack_size(*a) / 2)
	{
		while (loc_a > 0)
		{
			ra(a);
			loc_a--;
		}
	}
	else if (*a && loc_a >= stack_size(*a) / 2)
	{
		while (loc_a < stack_size(*a))
		{
			rra(a);
			loc_a++;
		}
	}
}

void	rot_else_b(t_list **b, int loc_b)
{
	if (*b && loc_b <= stack_size(*b) / 2)
	{
		while (loc_b > 0)
		{
			rb(b);
			loc_b--;
		}
	}
	else if (*b && loc_b >= stack_size(*b) / 2)
	{
		while (loc_b < stack_size(*b))
		{
			rrb(b);
			loc_b++;
		}
	}
}

void	rot_else(t_list **a, t_list **b, int loc_a, int loc_b)
{
	rot_else_a(a, loc_a);
	rot_else_b(b, loc_b);
}

void	rot_until_b(t_list **stack, int data)
{
	int		loc;
	t_list	*s;

	loc = locate(*stack, data);
	if (loc == -1)
		return ;
	s = *stack;
	while (s->data != data)
	{
		if (loc < stack_size(s) / 2)
			rb(&s);
		else
			rrb(&s);
	}
	*stack = s;
}

void	rot_until(t_list **stack, int data)
{
	int		loc;
	t_list	*s;

	loc = locate(*stack, data);
	if (loc == -1)
		return ;
	s = *stack;
	while (s->data != data)
	{
		if (loc < stack_size(s) / 2)
			ra(&s);
		else
			rra(&s);
	}
	*stack = s;
}

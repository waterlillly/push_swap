/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/30 15:46:16 by lbaumeis         ###   ########.fr       */
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

void	rot_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		loc_a;
	int		loc_b;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	loc_a = locate_cheapest(a);
	loc_b = locate_cheapest(b);
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
		if (loc <= stack_size(s) / 2)
			ra(&s);
		else
			rra(&s);
	}
	*stack = s;
}

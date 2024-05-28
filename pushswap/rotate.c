/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 13:47:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_both_top(t_list **a, t_list **b, int loc_a, int loc_b)
{
	int	x;

	x = 0;
	while (loc_a > 0 || loc_b > 0)
	{
		if (loc_a > 0 && loc_b > 0)
		{
			x += rr(a, b);
			loc_a--;
			loc_b--;
		}
		else if (loc_a > 0)
		{
			x += ra(a);
			loc_a--;
		}
		else if (loc_b > 0)
		{
			x += rb(b);
			loc_b--;
		}
	}
	return (x);
}

int	rot_both_bot(t_list **a, t_list **b, int loc_a, int loc_b)
{
	int	x;

	x = 0;
	while (loc_a <= stack_size(*a) || loc_b <= stack_size(*b))
	{
		if (loc_a <= stack_size(*a) && loc_b <= stack_size(*b))
		{
			x += rrr(a, b);
			loc_a++;
			loc_b++;
		}
		else if (loc_a < stack_size(*a))
		{
			x += rra(a);
			loc_a++;
		}
		else if (loc_b < stack_size(*b))
		{
			x += rrb(b);
			loc_b++;
		}
	}
	return (x);
}

int	rot_else_a(t_list **a, int loc_a)
{
	int	x;

	x = 0;
	if (*a && loc_a <= stack_size(*a) / 2)
	{
		while (loc_a > 0)
		{
			x += ra(a);
			loc_a--;
		}
	}
	else if (*a && loc_a >= stack_size(*a) / 2)
	{
		while (loc_a < stack_size(*a))
		{
			x += rra(a);
			loc_a++;
		}
	}
	return (x);
}

int	rot_else_b(t_list **b, int loc_b)
{
	int	x;

	x = 0;
	if (*b && loc_b <= stack_size(*b) / 2)
	{
		while (loc_b > 0)
		{
			x += rb(b);
			loc_b--;
		}
	}
	else if (*b && loc_b >= stack_size(*b) / 2)
	{
		while (loc_b < stack_size(*b))
		{
			x += rrb(b);
			loc_b++;
		}
	}
	return (x);
}

int	rot_else(t_list **a, t_list **b, int loc_a, int loc_b)
{
	int	x;
	
	x = 0;
	x += rot_else_a(a, loc_a);
	x += rot_else_b(b, loc_b);
	return (x);
}

int	rot_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		loc_a;
	int		loc_b;
	t_list	*a;
	t_list	*b;
	int		x;

	a = *stack_a;
	b = *stack_b;
	loc_a = locate_cheapest(a);
	loc_b = locate_cheapest(b);
	x = 0;
	if (loc_a == -1 || loc_b == -1)
		return (-1);
	else if (a && b && (loc_a <= stack_size(a) / 2) && (loc_b <= stack_size(b) / 2))
		x += rot_both_top(&a, &b, loc_a, loc_b);
	else if (a && b && (loc_a > stack_size(a) / 2) && (loc_b > stack_size(b) / 2))
		x += rot_both_bot(&a, &b, loc_a, loc_b);
	else
		x += rot_else(&a, &b, loc_a, loc_b);
	*stack_a = a;
	*stack_b = b;
	return (x);
}

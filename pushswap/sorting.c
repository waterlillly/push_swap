/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 12:41:17 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five_max(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		elements;
	int		x;

	a = *stack_a;
	b = *stack_b;
	elements = stack_size(a);
	x = 0;
	if (elements == 3)
		x += sort_three(&a);
	else if (elements == 4)
	{
		x += rot_until(&a, find_min(a));
		x += pb(&a, &b);
		x += sort_three(&a);
		x += pa(&a, &b);
	}
	else if (elements == 5)
		x += sort_five(&a, &b);
	*stack_a = a;
	*stack_b = b;
	return (x);
}

int	sort_three(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (!s || !s->next || !s->next->next)
		return (-1);
	if (s->data < s->next->data)
		x += sort_three_a(&s);
	else
		x += sort_three_b(&s);
	*stack = s;
	return (x);
}

int	sort_three_a(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (s->next->data < s->next->next->data)
		return (-1);
	else
	{
		if (s->data < s->next->next->data)
		{
			x += rra(&s);
			x += sa(&s);
		}
		else
			x += rra(&s);
	}
	*stack = s;
	return (x);
}

int	sort_three_b(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (s->next->data < s->next->next->data)
	{
		if (s->data < s->next->next->data)
			x += sa(&s);
		else
			x += ra(&s);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			x += sa(&s);
			x += rra(&s);
		}
	}
	*stack = s;
	return (x);
}

int	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		y;
	t_list	*a;
	t_list	*b;
	int		x;

	y = 0;
	a = *stack_a;
	b = *stack_b;
	x = 0;
	while (y < 2)
	{
		x += rot_until(&a, find_min(a));
		x += pb(&a, &b);
		y++;
	}
	x += sort_three(&a);
	x += pa(&a, &b);
	x += pa(&a, &b);
	*stack_a = a;
	*stack_b = b;
	return (x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/06 22:34:56 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_list **stack_a, t_list **stack_b)
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
		sort_three(&a);
	else if (elements == 4)
	{
		rot_until(&a, find_min(a));
		pb(&a, &b);
		sort_three(&a);
		pa(&a, &b);
	}
	else if (elements == 5)
		sort_five(&a, &b);
	else
		x += sort_to_b(&a, &b);
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

int	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	int		x;
	//int		mid;
	
	x = 0;
	//mid = stack_size(*stack_a) / 2;
	while (!is_sorted(*stack_a) && stack_size(*stack_a) > 5)
	{
		x += rot_until(stack_a, find_min(*stack_a));
		x += pb(stack_a, stack_b);
		//mid--;
	}
	if (stack_size(*stack_a) == 5 && !is_sorted(*stack_a))
		x += sort_five(stack_a, stack_b);
	back_to_a(stack_a, stack_b);
	return (x);
}

int	back_to_a(t_list **stack_a, t_list **stack_b)
{
	int		x;
	
	x = 0;
	while (*stack_b)
	{
		x += rot_until(stack_a, find_min(*stack_a));
		x += pa(stack_a, stack_b);
		if ((*stack_a)->data > (*stack_a)->next->data)
			x += sa(stack_a);
	}
	return (x);
}

int	sort_both(t_list **stack_a, t_list **stack_b)
{
	int		x;
	int		y;
	
	x = 0;
	y = stack_size(*stack_a) / 2;
	while (y > 0)
	{
		x += pb(stack_a, stack_b);
		y--;
	}
	while (*stack_b)
	{
		x += rot_double(stack_a, stack_b, find_min(*stack_a), find_min(*stack_b));
		x += pa(stack_a, stack_b);
		if ((*stack_a)->data > (*stack_a)->next->data)
			x += sa(stack_a);
	}
	//if (!is_sorted(*stack_a))
	//	x += sort_both(stack_a, stack_b);
	return (x);
}

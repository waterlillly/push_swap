/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 18:16:41 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	how_to_sort(t_list **a, t_list **b)
{
	if (!is_sorted(*a) && stack_size(*a) <= 5)
		sort_five_max(a, b);
	else if (!is_sorted(*a))
	{
		rot_until(a, find_min(*a));
		pb(a, b);
		pb(a, b);
	}
	a_to_b(a, b);
	if (!is_sorted(*a))
		sort_three(a);
	b_to_a(a, b);
	rot_until(a, find_min(*a));
}

void	a_to_b(t_list **a, t_list **b)
{
	while (!is_sorted(*a) && stack_size(*a) > 3)
	{
		update(a, b);
		rot_cheapest(a, b);
		pb(a, b);
	}
}

void	b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		final(a, b);
		rot_cheapest(a, b);
		pa(a, b);
	}
}

void	sort_five_max(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		elements;

	a = *stack_a;
	b = *stack_b;
	elements = stack_size(a);
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
	*stack_a = a;
	*stack_b = b;
}

void	sort_three(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (!s || !s->next || !s->next->next)
		return ;
	if (s->data < s->next->data)
		sort_three_a(&s);
	else
		sort_three_b(&s);
	*stack = s;
}

void	sort_three_a(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (s->next->data < s->next->next->data)
		return ;
	else
	{
		if (s->data < s->next->next->data)
		{
			rra(&s);
			sa(&s);
		}
		else
			rra(&s);
	}
	*stack = s;
}

void	sort_three_b(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (s->next->data < s->next->next->data)
	{
		if (s->data < s->next->next->data)
			sa(&s);
		else
			ra(&s);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			sa(&s);
			rra(&s);
		}
	}
	*stack = s;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		y;
	t_list	*a;
	t_list	*b;

	y = 0;
	a = *stack_a;
	b = *stack_b;
	while (y < 2)
	{
		rot_until(&a, find_min(a));
		pb(&a, &b);
		y++;
	}
	sort_three(&a);
	pa(&a, &b);
	pa(&a, &b);
	*stack_a = a;
	*stack_b = b;
}

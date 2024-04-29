/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/29 21:21:49 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int partition(t_list **stack, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = (*stack)->data;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if ((*stack)->data < pivot)
		{
			i++;
			sa(stack);
		}
		ra(stack);
		j++;
	}
	sa(stack);
	return (i + 1);
}

void part_sort(t_list **stack, int low, int high)
{
	int pi;
	
	pi = 0;
	if (low < high) 
	{
		pi = partition(stack, low, high);
		part_sort(stack, low, pi - 1);
		part_sort(stack, pi + 1, high);
	}
}

void last_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		elements;
	
	a = *stack_a;
	b = *stack_b;
	elements = stack_size(a);
	if (elements <= 1)
		return ;
	part_sort(&a, 0, elements - 1);
	*stack_a = a;
	*stack_b = b;
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

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		x;

	a = *stack_a;
	b = *stack_b;
	x = 0;
	while (a)
	{
		if (!b)
			pb(&a, &b);
		x = rot_double(&a, &b, find_max(a), find_max(b));
		if (x == -1)
			return ;
		pb(&a, &b);
		if (b->data < b->next->data)
			sb(&b);
	}
	pushback(&a, &b);
	*stack_a = a;
	*stack_b = b;
}

void	pushback(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	pa(&a, &b);
	while (b != NULL)
	{
		while (a->data < b->data)
		{
			if (a->next->data < a->data)
				sa(&a);
			ra(&a);
		}
		pa(&a, &b);
	}
	*stack_a = a;
	*stack_b = b;
}

void	sort(t_list **stack_a, t_list **stack_b)
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
	else
		sort_more(&a, &b);
	if (!is_sorted(a))
		last_sort(&a, &b);
	*stack_a = a;
	*stack_b = b;
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

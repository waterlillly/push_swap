/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:53:47 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	while (a)
	{
		b = *stack_b;
		if (a->data < find_min(b))
		{
			while (b->data != find_max(b))
				b = b->next;
			a->target = b;
		}
		else
			get_target_a_2(&a, &b);
		a = a->next;
	}
}

void	get_target_a_2(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		diff;
	int		min_diff;

	a = *stack_a;
	b = *stack_b;
	a->target = b;
	min_diff = INT_MAX;
	while (b)
	{
		if (b->data > a->data)
		{
			diff = b->data - a->data;
			if (diff < min_diff)
			{
				min_diff = diff;
				a->target = b;
			}
		}
		b = b->next;
	}
}

void	update_price_a(t_list *a, t_list *b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b)
		return ;
	update_price_a_2(a, b, size_a, size_b);
}

void	update_price_a_2(t_list *a, t_list *b, int size_a, int size_b)
{
	t_list	*t;

	while (a && b)
	{
		t = a->target;
		if ((a->index <= size_a / 2) && (t->index <= size_b / 2))
		{
			if (a->index < t->index)
				a->price = t->index;
			else
				a->price = a->index;
		}
		else if ((a->index > size_a / 2) && (t->index > size_b / 2))
		{
			if (a->index < t->index)
				a->price = t->index;
			else
				a->price = a->index;
		}
		else if ((a->index <= size_a / 2) && (t->index > size_b / 2))
			a->price = a->index + (size_b - t->index);
		else if ((a->index > size_a / 2) && (t->index <= size_b / 2))
			a->price = (size_a - a->index) + t->index;
		a = a->next;
	}
}

void	update(t_list **a, t_list **b)
{
	get_target_a(a, b);
	update_index(a);
	update_index(b);
	update_price_a(*a, *b);
	update_cheapest(a);
}

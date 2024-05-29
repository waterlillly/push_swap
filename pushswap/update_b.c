/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:24:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 12:15:59 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		if (b->data > find_max(a))
		{
			while (a->data != find_min(a))
				a = a->next;
			b->target = a;
		}
		else
			get_target_b_2(&a, &b);
		b = b->next;
	}
}

void	get_target_b_2(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		diff;
	int		min_diff;

	a = *stack_a;
	b = *stack_b;
	b->target = a;
	min_diff = INT_MIN;
	while (a)
	{
		if (b->data < a->data)
		{
			diff = a->data - b->data;
			if (diff < min_diff)
			{
				min_diff = diff;
				b->target = a;
			}
		}
		a = a->next;
	}
}

void	update_price_b(t_list *a, t_list *b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b)
		return ;
	update_price_b_2(a, b, size_a, size_b);
}

void	update_price_b_2(t_list *a, t_list *b, int size_a, int size_b)
{
	t_list	*t;
	
	while (b && a)
	{
		t = b->target;
		if ((b->index <= size_b / 2) && (t->index <= size_a / 2))
		{
			if (b->index < t->index)
				b->price = t->index;
			else
				b->price = b->index;
		}
		else if ((b->index > size_b / 2) && (t->index > size_a / 2))
		{
			if (b->index < t->index)
				b->price = t->index;
			else
				b->price = b->index;
		}
		else if ((b->index <= size_b / 2) && (t->index > size_a / 2))
			b->price = b->index + (size_a - t->index);
		else if ((b->index > size_b / 2) && (t->index <= size_a / 2))
			b->price = (size_b - b->index) + t->index;
		b = b->next;
	}
}

void	final(t_list **a, t_list **b)
{
	get_target_b(a, b);
	update_index(a);
	update_index(b);
	update_price_b(*a, *b);
	update_cheapest(b);
}

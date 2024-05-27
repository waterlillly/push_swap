/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:24:41 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 15:31:46 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_target_a(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;
	
	a = *stack_a;
	b = *stack_b;
	while (a)
	{
		b = *stack_b;
		x = b->data;
		a->target = b;
		while (b)
		{
			if (x < b->data && a->data > b->data)
			{
				x = b->data;
				a->target = b;
			}
			b = b->next;
		}
		a = a->next;
	}
}

void	update_price_a(t_list *a, t_list *b)
{
	int		size_a;
	int		size_b;
	t_list	*t;

	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b)
		return ;
	while (a && b)
	{
		t = a->target;
		if ((a->index <= size_a / 2) && (t->index <= size_b / 2))
		{
			if (a->index < t->index)
				a->price = a->index + (t->index - a->index);
			else
				a->price = t->index + (a->index - t->index);
		}
		else if ((a->index > size_a / 2) && (t->index > size_b / 2))
		{
			if (a->index < t->index)
				a->price = a->index + (t->index - a->index);
			else
				a->price = t->index + (a->index - t->index);
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
	update_index_target(a);
	update_index(b);
	update_price_a(*a, *b);
	update_cheapest(a);
	//update_cheapest_target(a);
}

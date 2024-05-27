/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:24:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 15:31:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_target_b(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;
	
	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		x = a->data;
		b->target = a;
		while (a)
		{
			if (x < a->data && b->data < a->data)
			{
				x = a->data;
				b->target = a;
			}
			a = a->next;
		}
		b = b->next;
	}
}

void	update_price_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;

	a = *stack_a;
	b = *stack_b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b || !b->target)
		return ;
	while (b && b->target && a)
	{
		if ((b->index <= size_b / 2) && (b->target->index <= size_a / 2))
		{
			if (b->index < b->target->index)
				b->price = b->index + (b->target->index - b->index);
			else
				b->price = b->target->index + (b->index - b->target->index);
		}
		else if ((b->index > size_b / 2) && (b->target->index > size_a / 2))
		{
			if (b->index < b->target->index)
				b->price = b->index + (b->target->index - b->index);
			else
				b->price = b->target->index + (b->index - b->target->index);
		}
		else if ((b->index <= size_b / 2) && (b->target->index > size_a / 2))
			b->price = b->index + (size_a - b->target->index);
		else if ((b->index > size_b / 2) && (b->target->index <= size_a / 2))
			b->price = (size_b - b->index) + b->target->index;
		ft_printf("price: %d\ntarget: %d\n", b->price, b->target->data);
		b = b->next;
	}
}

void	final(t_list **a, t_list **b)
{
	get_target_b(a, b);
	update_index(a);
	update_index(b);
	update_price_b(a, b);
	update_cheapest(b);
}

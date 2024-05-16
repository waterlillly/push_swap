/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/16 22:50:18 by lbaumeis         ###   ########.fr       */
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
		x = find_max(b);
		while (b)
		{
			if (x > b->data && a->data > b->data)
			{
				x = b->data;
				a->target = b;
			}
			b = b->next;
		}
		*stack_b = b;
		a = a->next;
	}
	*stack_a = a;
}

void get_target_b(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;
	
	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		x = find_min(a);
		while (a)
		{
			if (x < a->data && b->data < a->data)
			{
				x = a->data;
				b->target = a;
			}
			a = a->next;
		}
		*stack_a = a;
		b = b->next;
	}
	*stack_b = b;
}

void	update_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = *stack_a;
	b = *stack_b;
	i = 0;
	while (a)
	{
		a->index = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->index = i;
		i++;
		b = b->next;
	}
	*stack_a = a;
	*stack_b = b;
}

int	get_price(t_list *a, t_list *b, char c)
{
	int	cost;

	cost = 0;
	if (c == 'a')
	{
		if (a->index < stack_size(a) / 2)
			cost = a->index;
		else
			cost = stack_size(a) - a->index;
		if (a->target->index < stack_size(b) / 2)
			cost += a->target->index;
		else
			cost += stack_size(b) - a->target->index;
	}
	else if (c == 'b')
	{
		if (b->index < stack_size(b) / 2)
			cost = b->index;
		else
			cost = stack_size(b) - b->index;
		if (b->target->index < stack_size(a) / 2)
			cost += b->target->index;
		else
			cost += stack_size(a) - b->target->index;
	}
	return (cost);
}

void	update_price(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	update_index(stack_a, stack_b);
	while (a)
	{
		a->price = get_price(a, b, 'a');
		a = a->next;
	}
	while (b)
	{
		b->price = get_price(a, b, 'b');
		b = b->next;
	}
	*stack_a = a;
	*stack_b = b;
}

void	update_cheapest(t_list **stack)
{
	t_list	*s;

	s = *stack;
	while (s)
	{
		s->cheapest = 1;
		if (s->next && s->next->price < s->price)
			s->cheapest = 0;
		s = s->next;
	}
	*stack = s;
}

int	locate_cheapest(t_list *s)
{
	int		x;

	x = 0;
	while (s && s->cheapest != 1)
	{
		x++;
		s = s->next;
	}
	if (s->cheapest == 1)
		return (x);
	return (-1);
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
	loc_b = locate_cheapest(a->target);
	x = 0;
	if (loc_a == -1 || loc_b == -1)
		return (-1);
	while (a->cheapest != 1 && a->target->cheapest != 1)
	{
		if ((loc_a <= stack_size(a) / 2)
			&& (loc_b <= stack_size(b) / 2))
			x += rr(&a, &b);
		else if ((loc_a > stack_size(a) / 2)
			&& (loc_b > stack_size(b) / 2))
			x += rrr(&a, &b);
		else
		{
			if (loc_a <= stack_size(a) / 2)
				x += ra(&a);
			else if (loc_a > stack_size(a) / 2)
				x += rra(&a);
			if (loc_b <= stack_size(b) / 2)
				x += rb(&b);
			else if (loc_b > stack_size(b) / 2)
				x += rrb(&b);
		}
	}
	*stack_a = a;
	*stack_b = b;
	return (x);
}

void	update(t_list **a, t_list **b)
{
	get_target_a(a, b);
	update_price(a, b);
	update_cheapest(a);
}

void	final(t_list **a, t_list **b)
{
	get_target_b(a, b);
	update_price(a, b);
	update_cheapest(b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/20 17:42:07 by lbaumeis         ###   ########.fr       */
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
		b = *stack_b;
		while (b)
		{
			if (x > b->data && a->data > b->data)
			{
				x = b->data;
				a->target = b;
			}
			b = b->next;
		}
		a = a->next;
	}
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
		a = *stack_a;
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

void	update_index(t_list **stack)
{
	t_list	*s;
	int		i;

	s = *stack;
	i = 0;
	while (s)
	{
		s->index = i;
		i++;
		s = s->next;
	}
}

void	update_cheapest(t_list **stack)
{
	t_list	*s;
	t_list	*cur_cheap;

	s = *stack;
	cur_cheap = s;
	s->cheapest = 0;
	s = s->next;
	while (s)
	{
		if (s && cur_cheap->price > s->price)
		{
			cur_cheap->cheapest = 0;
			s->cheapest = 1;
			cur_cheap = s;
		}
		else
		{
			cur_cheap->cheapest = 1;
			s->cheapest = 0;
		}
		s = s->next;
	}
}

int	locate_cheapest(t_list *s)
{
	int		x;

	x = 0;
	while (s)
	{
		if (s->cheapest == 1)
			return (x);
		x++;
		s = s->next;
	}
	return (-1);
}

int	rot_both_top(t_list **a, t_list **b, int loc_a, int loc_b)
{
	int	x;

	x = 0;
	while (loc_a > 0 && loc_b > 0)
	{
		x += rr(a, b);
		loc_a--;
		loc_b--;
	}
	while (loc_a > 0)
	{
		x += ra(a);
		loc_a--;
	}
	while (loc_b > 0)
	{
		x += rb(b);
		loc_b--;
	}
	return (x);
}

int	rot_both_bot(t_list **a, t_list **b, int loc_a, int loc_b)
{
	int	x;

	x = 0;
	while (loc_a < stack_size(*a) && loc_b < stack_size(*b))
	{
		x += rrr(a, b);
		loc_a++;
		loc_b++;
	}
	while (loc_a < stack_size(*a))
	{
		x += rra(a);
		loc_a++;
	}
	while (loc_b < stack_size(*b))
	{
		x += rrb(b);
		loc_b++;
	}
	return (x);
}

int	rot_else(t_list **a, t_list **b, int loc_a, int loc_b)
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
	else if (*a && loc_a > stack_size(*a) / 2)
	{
		while (loc_a <= stack_size(*a))
		{
			x += rra(a);
			loc_a++;
		}
	}
	if (*b && loc_b <= stack_size(*b) / 2)
	{
		while (loc_b > 0)
		{
			x += rb(b);
			loc_b--;
		}
	}
	else if (*b && loc_b > stack_size(*b) / 2)
	{
		while (loc_b <= stack_size(*b))
		{
			x += rrb(b);
			loc_b++;
		}
	}
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
	loc_b = locate_cheapest(a->target);
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

void	update(t_list **a, t_list **b)
{
	get_target_a(a, b);
	update_index(a);
	update_index(b);
	update_price_a(a, b);
	update_cheapest(a);
}

void	final(t_list **a, t_list **b)
{
	get_target_b(a, b);
	update_index(a);
	update_index(b);
	update_price_b(a, b);
	update_cheapest(b);
}

void	update_price_a(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;

	x = 0;
	a = *stack_a;
	b = *stack_b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b)
		return ;
	while (a && a->target && b)
	{
		if ((a->index < size_a / 2) && (a->target->index < size_b / 2))
		{
			if (a->index < a->target->index)
				x = a->index + (a->target->index - a->index);
			else
				x = a->target->index + (a->index - a->target->index);
		}
		else if ((a->index >= size_a / 2) && (a->target->index >= size_b / 2))
		{
			if (a->index < a->target->index)
				x = a->index + (a->target->index - a->index);
			else
				x = a->target->index + (a->index - a->target->index);
		}
		else if ((a->index < size_a / 2) && (a->target->index >= size_b / 2))
			x = a->index + (size_b - a->target->index);
		else if ((a->index >= size_a / 2) && (a->target->index < size_b / 2))
			x = (size_a - a->index) + a->target->index;
		a->price = x;
		a = a->next;
	}
}

void	update_price_b(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;

	x = 0;
	a = *stack_a;
	b = *stack_b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b)
		return ;
	while (b && b->target && a)
	{
		if ((b->index < size_b / 2) && (b->target->index < size_a / 2))
		{
			if (b->index < b->target->index)
				x = b->index + (b->target->index - b->index);
			else
				x = b->target->index + (b->index - b->target->index);
		}
		else if ((b->index >= size_b / 2) && (b->target->index >= size_a / 2))
		{
			if (b->index < b->target->index)
				x = b->index + (b->target->index - b->index);
			else
				x = b->target->index + (b->index - b->target->index);
		}
		else if ((b->index < size_b / 2) && (b->target->index >= size_a / 2))
			x = b->index + (size_a - b->target->index);
		else if ((b->index >= size_b / 2) && (b->target->index < size_a / 2))
			x = (size_b - b->index) + b->target->index;
		b->price = x;
		b = b->next;
	}
}

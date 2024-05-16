/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:13:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/08 17:43:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cur_index(t_list *s)
{
	int	i;
	int	mid;

	i = 0;
	if (!s)
		return ;
	mid = stack_size(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= mid)
			s->top_half = true;
		else
			s->top_half = false;
		s = s->next;
		i++;
	}
}

static void	a_target_b(t_list *a, t_list *b)
{
	t_list	*cur_b;
	t_list	*target;
	int		match_index;

	while (a)
	{
		match_index = INT_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->data < a->data && cur_b->data > match_index)
			{
				match_index = cur_b->data;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (match_index == INT_MIN)
			a->target->data = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	a_price_eval(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->price = a->index;
		if (!(a->top_half))
			a->price = len_a - (a->index);
		if (a->target->top_half)
			a->price += a->target->index;
		else
			a->price += len_b - (a->target->index);
		a = a->next;
	}
}

t_list	*get_cheapest(t_list *s)
{
	int		c_value;
	t_list	*c_node;

	if (!s)
		return (NULL);
	c_value = INT_MAX;
	while (s)
	{
		if (s->price < c_value)
		{
			c_value = s->price;
			c_node = s;
		}
		s = s->next;
	}
	return (c_node);
}

void	prepare_a(t_list *a, t_list *b)
{
	cur_index(a);
	cur_index(b);
	a_target_b(a, b);
	a_price_eval(a, b);
	get_cheapest(a);
}

static int	a_to_b(t_list **a, t_list **b)
{
	t_list	*c_node;
	int		x;

	x = 0;
	c_node = get_cheapest(*a);
	x += rot_double(a, b, c_node->data, c_node->target->data);
	x += pb(a, b);
	return (x);
}

static int	b_to_a(t_list **a, t_list **b)
{
	int	x;

	x = 0;
	x += rot_until(a, (*b)->target->data);
	x += pa(a, b);
	return (x);
}

static void	b_target_a(t_list *a, t_list *b)
{
	t_list	*cur_a;
	t_list	*target;
	int		match_index;

	while (b)
	{
		match_index = INT_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->data < b->data && cur_a->data > match_index)
			{
				match_index = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (match_index == INT_MAX)
			b->target->data = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	prepare_b(t_list *a, t_list *b)
{
	cur_index(a);
	cur_index(b);
	b_target_a(a, b);
}

int	sort_more(t_list **a, t_list **b)
{
	int		x;
	int		len;

	x = 0;
	len = stack_size(*a);
	if (!is_sorted(*a))
	{
		x += pb(a, b);
		x += pb(a, b);
		len -= 2;
	}
	while (len > 3 && !is_sorted(*a))
	{
		prepare_a(*a, *b);
		x += a_to_b(a, b);
		len--;
	}
	x += sort_three(a);
	while(*b)
	{
		prepare_b(*a, *b);
		x += b_to_a(a, b);
	}
	cur_index(*a);
	x += rot_until(a, find_min(*a));
	return (x);
}

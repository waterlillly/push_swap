/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:38:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 14:35:35 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	update_index_target(t_list **stack)
{
	t_list	*s;
	t_list	*t;
	int		i;

	s = *stack;
	i = 0;
	while (s)
	{
		t = s->target;
		t->index = i;
		i++;
		s = s->next;
	}
}
/*
void	update_cheapest(t_list **stack)
{
	t_list	*s;

	s = *stack;
	s->cheapest = 0;
	while (s->next)
	{
		if (s && s->next->price > s->price)
			s->cheapest = 1;
		else
		{
			s->next->cheapest = 1;
			s->cheapest = 0;
		}
		if (s->price == 0)
		{
			s = s->next;
			while (s)
			{
				s->cheapest = 0;
				s = s->next;
			}
			return ;
		}
		s = s->next;
	}
}
*/
void	update_cheapest(t_list **stack)
{
	t_list	*s;
	int min;

	s = *stack;
	min = s->price;
	s->cheapest = 0;
	while (s)
	{
		if (min > s->price)
			min = s->price;
		s->cheapest = 0;
		s = s->next;
	}
	s = *stack;
	while (s)
	{
		if (min == s->price)
		{
			s->cheapest = 1;
			return ;
		}
	}
}

/*
void	update_cheapest_target(t_list **stack)
{
	t_list	*s1;
	t_list	*s2;
	t_list	*t1;
	t_list	*t2;

	s1 = *stack;
	s1->cheapest = 0;
	while (s1 && s1->next)
	{
		s2 = s1->next;
		t1 = s1->target;
		t2 = s2->target;
		if (t1 && t2 && t2->price > t1->price)
		{
			t1->cheapest = 1;
			t2->cheapest = 0;
		}
		else
		{
			t1->cheapest = 0;
			t2->cheapest = 1;
		}
		s1 = s1->next;
	}
}
*/
int	locate_cheapest(t_list *s)
{
	int	x;

	x = 0;
	if (!s)
		return (-1);
	while (s)
	{
		if (s && s->cheapest)
			return (x);
		x++;
		s = s->next;
	}
	return (x);
}
/*
int	locate_cheapest_target(t_list *s)
{
	int		x;
	t_list	*t;

	x = 0;
	if (!s)
		return (-1);
	while (s)
	{
		t = s->target;
		if (t->cheapest)
			return (x);
		x++;
		s = s->next;
	}
	if (x > stack_size(s))
		return (-1);
	return (x);
}
*/
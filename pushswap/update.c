/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:38:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 14:57:45 by lbaumeis         ###   ########.fr       */
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

void	update_cheapest(t_list **stack)
{
	t_list	*s;
	int min;

	s = *stack;
	if (!s)
		return ;
	min = INT_MAX;
	while (s)
	{
		if (min > s->price)
			min = s->price;
		s = s->next;
	}
	s = *stack;
	if (min == INT_MAX)
		return ;
	while (s)
	{
		if (min == s->price)
		{
			s->cheapest = 1;
			return ;
		}
	}
}

int	locate_cheapest(t_list *s)
{
	int	x;

	x = -1;
	while (s)
	{
		x++;
		if (s->cheapest == 1)
			return (x);
		s = s->next;
	}
	return (x);
}

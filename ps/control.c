/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:27:38 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/08 02:32:09 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list **stack)
{
	int		x;
	t_list	*s;

	x = 0;
	s = *stack;
	while (s && s->next)
	{
		x++;
		s = s->next;
	}
	return (x);
}

int	find_min(t_list **stack)
{
	int		min;
	t_list	*s;

	min = INT_MAX;
	s = *stack;
	if (!s)
		return (ft_printf("wrong min\n"));
	while (s && s->next)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}

int	find_max(t_list **stack)
{
	int		max;
	t_list	*s;

	max = INT_MIN;
	s = *stack;
	if (!s)
		return (ft_printf("wrong max\n"));
	while (s && s->next)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

int	is_sorted(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (s == NULL || s->next == NULL)
		return (0);
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
        s = s->next;
	}
	return (1);
}

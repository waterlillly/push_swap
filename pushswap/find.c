/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:22:44 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 12:29:31 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *s)
{
	int	x;

	x = INT_MIN;
	while (s)
	{
		if (s->data > x)
			x = s->data;
		s = s->next;
	}
	return (x);
}

int	find_min(t_list *s)
{
	int	x;

	x = INT_MAX;
	while (s)
	{
		if (s->data < x)
			x = s->data;
		s = s->next;
	}
	return (x);
}

int	find_mid(t_list *s)
{
	int	half;
	int	x;
	int	mid;

	half = stack_size(s) / 2;
	x = 0;
	mid = find_min(s);
	while (s && x <= half && mid < find_max(s))
	{
		if (mid < s->data)
		{
			mid = s->data;
			x++;
		}
		s = s->next;
	}
	return (mid);
}

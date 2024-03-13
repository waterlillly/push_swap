/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:10:23 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/13 06:18:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list **a)
{
	int		max;
	t_list	*cur;
	
	cur = *a;
	max = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (max < cur->next->data)
			max = cur->next->data;
		cur = cur->next;
	}
	return (max);
}

int	next_min(t_list **a, int repeat, int min)
{
	t_list	*cur;
	int		new_min;

	cur = *a;
	new_min = min + 1;
	if (repeat == 0)
		return (min);
	else if (repeat > 0)
	{
		while (cur != 0 && cur->next != 0)
		{
			if (new_min > min && new_min >= cur->data)
				new_min = cur->data;
			cur = cur->next;
		}
		return (next_min(a, repeat - 1, new_min));
	}
	else
		return (2147483647);
}

int	min(t_list **a, int repeat)
{
	int		min;
	t_list	*cur;
	
	cur = *a;
	min = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	if (repeat > 0)
		return (next_min(a, repeat, min));
	else
		return (min);
}

int	mid(int ac, t_list **a)
{
	int		mid_min;
	int		x;

	mid_min = 0;
	x = (ac - 1) / 2;
	mid_min = min(a, x);
	if (mid_min == 2147483647)
		return (error(4), 0);
	else
		return (mid_min);
}

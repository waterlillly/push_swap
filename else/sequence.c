/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:11:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/30 16:29:40 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many(t_list *a)
{
	int	c;

	c = 0;
	while (a)
	{
		if (a->seq == 1)
			c++;
		a = a->next;
	}
	return (c);
}

void	mark_seq(t_list *a)
{
	t_list	*cur;

	cur = a;
	a->seq = 1;
	while (a->next)
	{
		if (a->next->data > cur->data)
		{
			cur = a->next;
			a->next->seq = 1;
		}
		else
			a->next->seq = 0;
		a = a->next;
	}
}

void	reset_seq(t_list *a)
{
	while (a)
	{
		a->seq = 0;
		a = a->next;
	}
}

t_list	*best_start(t_list *a)
{
	int		max_len;
	int		cur_len;
	int		x;
	t_list	*best;

	max_len = 0;
	cur_len = 0;
	x = 0;
	best = a;
	while (a && x <= stack_size(a))
	{
		mark_seq(a);
		cur_len = how_many(a);
		if (cur_len > max_len)
		{
			max_len = cur_len;
			best = a;
		}
		reset_seq(a);
		a = a->next;
		x++;
	}
	mark_seq(best);
	return (best);
}

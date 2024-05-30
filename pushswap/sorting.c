/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/30 16:29:38 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	t_list	*start;
	int		x;

	if (!is_sorted(*a) && stack_size(*a) <= 5)
		sort_five_max(a, b);
	else if (!is_sorted(*a))
	{
		start = best_start(*a);
		rot_until(a, start->data);
		x = stack_size(*a);
		while (a && x > 0)
		{
			if ((*a)->seq == 0)
				pb(a, b);
			else
				ra(a);
			x--;
		}
	}
	b_to_a(a, b);
	rot_until(a, find_min(*a));
}

void	b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		final(a, b);
		rot_cheapest(a, b);
		pa(a, b);
	}
}

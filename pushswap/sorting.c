/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/30 11:51:03 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	int	x;

	x = 2;
	if (!is_sorted(*a) && stack_size(*a) <= 5)
		sort_five_max(a, b);
	else if (!is_sorted(*a))
	{
		while (x > 0)
		{
			if ((*a)->seq == 0)
			{
				pb(a, b);
				x--;
			}
			else
				rra(a);
		}
	}
	a_to_b(a, b);
	b_to_a(a, b);
	rot_until(a, find_min(*a));
}

void	a_to_b(t_list **a, t_list **b)
{
	while (!is_sorted(*a))
	{
		update(a, b);
		if (rot_cheapest(a, b) != -1)
			pb(a, b);
		else
			rra(a);
	}
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

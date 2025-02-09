/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:18:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list **a, t_list **b)
{
	if (!is_sorted(*a) && stack_size(*a) <= 5)
		sort_five_max(a, b);
	else 
	{
		if (!is_sorted(*a) && stack_size(*a) > 3)
		{
			pb(a, b);
			pb(a, b);
		}
		a_to_b(a, b);
		if (!is_sorted(*a))
			sort_three(a);
		b_to_a(a, b);
		rot_until(a, find_min(*a));
	}
}

void	a_to_b(t_list **a, t_list **b)
{
	while (!is_sorted(*a) && stack_size(*a) > 3)
	{
		update(a, b);
		rot_cheap(a, b);
		pb(a, b);
	}
}

void	b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		final(a, b);
		rot_cheap_b(a, b);
		pa(a, b);
	}
}

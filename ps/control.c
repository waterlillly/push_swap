/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:27:38 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/10 01:46:03 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list **stack)
{
	int		x;

	x = 0;
	while ((*stack))
	{
		x++;
		(*stack) = (*stack)->next;
	}
	return (x);
}

int	find_min(t_list **stack)
{
	int		min;

	min = INT_MAX;
	if (!(*stack))
		return (ft_printf("wrong min\n"), 0);
	while ((*stack) && (*stack)->next)
	{
		if ((*stack)->data < min)
			min = (*stack)->data;
		(*stack) = (*stack)->next;
	}
	return (min);
}

int	find_max(t_list **stack)
{
	int		max;

	max = INT_MIN;
	if (!(*stack))
		return (ft_printf("wrong max\n"), 0);
	while ((*stack) && (*stack)->next)
	{
		if ((*stack)->data > max)
			max = (*stack)->data;
		(*stack) = (*stack)->next;
	}
	return (max);
}

int	is_sorted(t_list **stack)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	while ((*stack) && (*stack)->next)
	{
		if ((*stack)->data > (*stack)->next->data)
			return (0);
        (*stack) = (*stack)->next;
	}
	return (1);
}

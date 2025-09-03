/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:17:19 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five_max(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		elements;

	a = *stack_a;
	b = *stack_b;
	elements = stack_size(a);
	if (elements == 2)
		sort_two(&a);
	if (elements == 3)
		sort_three(&a);
	else if (elements == 4)
	{
		rot_until(&a, find_min(a));
		pb(&a, &b);
		sort_three(&a);
		pa(&a, &b);
	}
	else if (elements == 5)
		sort_five(&a, &b);
	*stack_a = a;
	*stack_b = b;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		y;
	t_list	*a;
	t_list	*b;

	y = 0;
	a = *stack_a;
	b = *stack_b;
	while (y < 2)
	{
		rot_until(&a, find_min(a));
		pb(&a, &b);
		y++;
	}
	sort_three(&a);
	pa(&a, &b);
	pa(&a, &b);
	*stack_a = a;
	*stack_b = b;
}

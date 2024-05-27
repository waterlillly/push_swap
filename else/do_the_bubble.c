/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_bubble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:40:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 12:41:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_the_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		half;
	int		x;
	int		c;

	a = *stack_a;
	b = *stack_b;
	half = stack_size(a) / 2;
	x = find_mid(a);
	c = 0;
	while (a && half >= 0)
	{
		if (a->data < x)
		{
			c += pb(&a, &b);
			half--;
		}
		else
			c += ra(&a);
	}
	while (!(is_sorted(a)) && !(is_sorted(b)) && a && b)
	{
		if ((a->data > a->next->data) || (b->data < b->next->data))
			c += swapping(&a, &b);
		c += continuing(&a, &b);
	}
	x = rot_double(&a, &b, find_min(a), find_max(b));
	if (x < 0)
		return (-1);
	c += x;
	while (a && b)
		c += pa(&a, &b);
	return (c);
}

int	swapping(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;

	x = 0;
	a = *stack_a;
	b = *stack_b;
	if ((a->data > a->next->data) && (b->data < b->next->data))
		x += ss(&a, &b);
	else if (a->data > a->next->data)
		x += sa(&a);
	else if (b->data < b->next->data)
		x += sb(&b);
	x += continuing(&a, &b);
	*stack_a = a;
	*stack_b = b;
	return (x);
}

int	continuing(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*a;
	t_list	*b;

	x = 0;
	a = *stack_a;
	b = *stack_b;
	if ((a->data < a->next->data) && (b->data > b->next->data))
		x += rr(&a, &b);
	else if (a->data < a->next->data)
		x += ra(&a);
	else if (b->data > b->next->data)
		x += rb(&b);
	*stack_a = a;
	*stack_b = b;
	return (x);
}

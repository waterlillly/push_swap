/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:08:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 12:49:59 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_both_top(t_list **a, t_list **b, int loc_a, int loc_b)
{
	while (loc_a > 0 || loc_b > 0)
	{
		if (loc_a > 0 && loc_b > 0)
		{
			rr(a, b);
			loc_a--;
			loc_b--;
		}
		else if (loc_a > 0)
		{
			ra(a);
			loc_a--;
		}
		else if (loc_b > 0)
		{
			rb(b);
			loc_b--;
		}
	}
}

void	rot_both_bot(t_list **a, t_list **b, int loc_a, int loc_b)
{
	while (loc_a <= stack_size(*a) || loc_b <= stack_size(*b))
	{
		if (loc_a <= stack_size(*a) && loc_b <= stack_size(*b))
		{
			rrr(a, b);
			loc_a++;
			loc_b++;
		}
		else if (loc_a < stack_size(*a))
		{
			rra(a);
			loc_a++;
		}
		else if (loc_b < stack_size(*b))
		{
			rrb(b);
			loc_b++;
		}
	}
}

void	rot_double(t_list **stack_a, t_list **stack_b, int data_a, int data_b)
{
	int	loc_a;
	int	loc_b;
	t_list	*a;
	t_list	*b;

	loc_a = locate(*stack_a, data_a);
	loc_b = locate(*stack_b, data_b);
	if (loc_a == -1 || loc_b == -1)
		return ;
	a = *stack_a;
	b = *stack_b;
	while (a->data != data_a && b->data != data_b)
		rot_double_2(&a, &b, loc_a, loc_b);
	*stack_a = a;
	*stack_b = b;
}

void	rot_double_2(t_list **stack_a, t_list **stack_b, int loc_a, int loc_b)
{
	t_list	*a;
	t_list	*b;
	
	a = *stack_a;
	b = *stack_b;
	if ((loc_a <= stack_size(a) / 2)
			&& (loc_b <= stack_size(b) / 2))
			rr(&a, &b);
		else if ((loc_a > stack_size(a) / 2)
			&& (loc_b > stack_size(b) / 2))
			rrr(&a, &b);
		else
		{
			if (loc_a <= stack_size(a) / 2)
				ra(&a);
			else if (loc_a > stack_size(a) / 2)
				rra(&a);
			if (loc_b <= stack_size(b) / 2)
				rb(&b);
			else if (loc_b > stack_size(b) / 2)
				rrb(&b);
		}
}

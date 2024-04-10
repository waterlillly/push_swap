/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:11:05 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/10 01:48:38 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		steps;

	steps = 0;
	min = find_min(stack_a);
	max = find_max(stack_a);
	while (!is_sorted(stack_a))
	{
		while (*stack_a && (*stack_a)->data != min && (*stack_a)->data != max)
		{
			steps++;
			push(stack_a, stack_b);
			if (*stack_a && (*stack_a)->data == min)
			{
				steps++;
				rotate(stack_a);
			}
			else if (*stack_a && (*stack_a)->data == max)
			{
				steps++;
				reverse_rotate(stack_a);
			}
		}
		while (*stack_b && (*stack_b)->data != min && (*stack_b)->data != max)
		{
			steps++;
			push(stack_b, stack_a);
			if (*stack_b && (*stack_b)->data == min)
			{
				steps++;
				rotate(stack_b);
			}
			else if (*stack_b && (*stack_b)->data == max)
			{
				steps++;
				reverse_rotate(stack_b);
			}
		}
	}
	return (steps);
}

void	sort_numbers(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		x;

	len = stack_size(stack_a);
	x = 0;
	if (len == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			swap(stack_a);
			x++;
		}
		ft_printf("sorted with %d move(s)\n", x);
		return ;
	}
	else if (len == 3)
		x += sort_three(stack_a);
	else if (len == 5)
		x += sort_five(stack_a, stack_b);
	else
		x += sort_stack(stack_a, stack_b);
	if (x > 0)
		ft_printf("%d moves\n", x);
	return ;
}

int	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		x;

	x = 0;
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	x += 2;
	ft_printf("pb\npb\n");
	x += sort_three(stack_a);
	if ((*stack_b)->data < (*stack_b)->next->data)
	{
		swap(stack_b);
		x++;
		ft_printf("sb\n");
	}
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	x += 2;
	ft_printf("pa\npa\n");
	return (x);
}

int	sort_three_a(t_list **stack)
{
	int		x;

	x = 0;
	if ((*stack)->next->data < (*stack)->next->next->data)
		return (x);
	else
	{
		if ((*stack)->data < (*stack)->next->next->data)
		{
			reverse_rotate(stack);
			swap(stack);
			x += 2;
		}
		else
		{
			reverse_rotate(stack);
			x++;
		}
	}
	return (x);
}

int	sort_three_b(t_list **stack)
{
	int		x;

	x = 0;
	if ((*stack)->next->data < (*stack)->next->next->data)
	{
		if ((*stack)->data < (*stack)->next->next->data)
			swap(stack);
		else
			rotate(stack);
		x++;
	}
	else
	{
		if ((*stack)->data > (*stack)->next->next->data)
		{
			swap(stack);
			reverse_rotate(stack);
			x += 2;
		}
	}
	return (x);
}

int	sort_three(t_list **stack)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	else
	{
		(*stack) = (*stack)->next;
		if (!(*stack) || !(*stack)->next)
			return (0);
		else
			(*stack) = (*stack)->prev;
		if ((*stack)->data < (*stack)->next->data)
			return (sort_three_a(stack));
		else
			return (sort_three_b(stack));
	}
	return (0);
}

/*
int	calculate_moves(int first, int second, int third)
{
	int	moves;

	moves = 0;
	if (first < second && first < third)
		moves += 0;
	else if (first < second || first < third)
		moves += 1;
	else
		moves += 2;
	if (second < first && second < third)
		moves += 0;
	else if (second < first || second < third)
		moves += 1;
	else
		moves += 2;
	if (third < first && third < second)
		moves += 0;
	else if (third < first || third < second)
		moves += 1;
	else
		moves += 2;
	return (moves);
}
*/

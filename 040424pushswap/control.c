/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:46 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/04 20:09:49 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] && i >= 0)
		free(s[i--]);
	s = NULL;
	free(s);
}

void	ft_free_list(t_list *s)
{
	if (s->next != 0)
		s = s->next;
	while (s != 0 && s->next != 0)
	{
		free(s->prev);
		s = s->next;
	}
	free(s->prev);
	s = 0;
	free(s);
}

int	presorted(char **arr, int x)
{
	while (arr[x] && arr[x + 1] && valid(arr[x]) && valid (arr[x + 1]))
	{
		if (ft_atoi(arr[x]) < ft_atoi(arr[x + 1]))
			x++;
		else
			return (0);
	}
	if (arr[x + 1] == NULL)
		return (ft_printf("no need to sort\n"), 1);
	else
		return (0);
}

int	valid(char *str)
{
	if (ft_atoi(str))
		return (1);
	return (0);
}

int	stack_size(t_list *s)
{
	int		x;

	x = 0;
	while (s && s->next)
	{
		x++;
		s = s->next;
	}
	return (x);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;
	int	steps;

	steps = 0;
	while (!is_sorted(*stack_a))
	{
		min = find_min(*stack_a);
		max = find_max(*stack_a);
		while (*stack_a && (*stack_a)->data != min && (*stack_a)->data != max)
		{
			steps++;
			pb(stack_a, stack_b);
		}
		if (*stack_a && (*stack_a)->data == min)
		{
			steps++;
			ra(stack_a);
		}
		else if (*stack_a && (*stack_a)->data == max)
		{
			steps++;
			rra(stack_a);
		}
		while (*stack_b && (*stack_b)->data != min && (*stack_b)->data != max)
		{
			steps++;
			pa(stack_b, stack_a);
		}
		if (*stack_b && (*stack_b)->data == min)
		{
			steps++;
			rb(stack_b);
		}
		else if (*stack_b && (*stack_b)->data == max)
		{
			steps++;
			rrb(stack_b);
		}
	}
	return (steps);
}

int	find_min(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

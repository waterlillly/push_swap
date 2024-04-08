/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:11:05 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/08 02:39:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		steps;
	t_list	*a;
	t_list	*b;

	steps = 0;
	a = *stack_a;
	b = *stack_b;
	min = find_min(stack_a);
	max = find_max(stack_a);
	while (!is_sorted(stack_a))
	{
		while (a && a->data != min && a->data != max)
		{
			steps++;
			push(&a, &b);
			if (a && a->data == min)
			{
				steps++;
				rotate(&a);
			}
			else if (a && a->data == max)
			{
				steps++;
				reverse_rotate(&a);
			}
		}
		while (b && b->data != min && b->data != max)
		{
			steps++;
			push(&b, &a);
			if (b && b->data == min)
			{
				steps++;
				rotate(&b);
			}
			else if (b && b->data == max)
			{
				steps++;
				reverse_rotate(&b);
			}
		}
	}
	return (steps);
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

void	sort_numbers(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		len;
	int		x;

	a = *stack_a;
	b = *stack_b;
	len = stack_size(&a);
	x = 0;
	if (len == 2)
	{
		if (a->data > a->next->data)
		{
			swap(&a);
			x++;
		}
		else
		{
			ft_printf("0 moves-> already sorted");
			return ;
		}
	}
	else if (len == 3)
		x += sort_three(&a);
	else if (len == 5)
		x += sort_five(&a, &b);
	else
		x += sort_stack(stack_a, stack_b);
	if (x > 0)
		ft_printf("%d moves\n", x);
	return ;
}

int	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		x;
	t_list	*b;

	x = 0;
	b = *stack_b;
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	x += 2;
	ft_printf("pb\npb\n");
	x += sort_three(stack_a);
	if (b->data < b->next->data)
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
	t_list	*s;

	x = 0;
	s = *stack;
	if (s->next->data < s->next->next->data)
		return (x);
	else
	{
		if (s->data < s->next->next->data)
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
	t_list	*s;

	x = 0;
	s = *stack;
	if (s->next->data < s->next->next->data)
	{
		if (s->data < s->next->next->data)
			swap(stack);
		else
			rotate(stack);
		x++;
	}
	else
	{
		if (s->data > s->next->next->data)
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
	t_list	*s;

	s = *stack;
	if (!s || !s->next)
		return (0);
	else
	{
		s = s->next;
		if (!s || !s->next)
			return (0);
		else
			s = s->prev;
		if (s->data < s->next->data)
			return (sort_three_a(stack));
		else
			return (sort_three_b(stack));
	}
	return (0);
}

/*
void	sort_three(t_list *stack_a)
{
	int	first;
	int	second;
	int	third;
	int	moves;

	first = stack_a->data;
	second = stack_a->next->data;
	third = stack_a->next->next->data;
	moves = calculate_moves(first, second, third);
	if (moves == 0)
		return ;
	else
	{
		print_sort_three(first, second, third);
		return ;
	}
}

void	print_sort_three(int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second > third)
			printf("sa\n");
		else
			printf("ra\n");
	}
	else if (second > first && second > third)
	{
		if (first > third)
			printf("rra\n");
		else
			printf("sa\n");
	}
	else if (third > first && third > second)
	{
		if (first > second)
			printf("ra\n");
		else
			printf("rra\n");
	}
}
*/
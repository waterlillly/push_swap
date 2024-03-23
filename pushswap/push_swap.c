/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:10:23 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/22 01:07:52 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_b_three(t_list *a, t_list *b)
{
	int	x;
	
	x = 0;
	while (b)
	{
		x++;
		b = b->next;
	}
	while (x <= 3)
	{
		pb(a, b);
		x++;
	}
}

t_list	*sort(t_list *a)
{
	t_list	*b;
	
	b = NULL;
	if (elements == 3)
		sort_three(a);
	else
	{
		b = (t_list *)malloc(sizeof(t_list) * (elements + 1));
		if (!b)
			return (ft_free(a), 0);
	}
	if (elements == 4)
	{
		while (a->data != min(a))
			ra(a);
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
	while (check_sort(a) != 1 || b)
	{
		ra(a);
		make_b_three(a, b);
		sort_three(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}
	return (ft_free(b), a);
}	

void	dd_sort(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*b;
	//int		min;
	//int		max;

	a = NULL;
	b = NULL;
	a = stack_a;
	b = stack_b;
	if (!a || !b)
		return ;
	//min = ft_min(stack_a, 0);
	//max = ft_max(stack_a);
	while (check_sort(stack_a) != 1)
	{
		if (b == 0)
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		//if (a->data == min || a->data == max)
		//	pb(stack_a, stack_b);
		a = a->next;
		if (a->data < a->prev->data)
		{
			if (a->data < a->next->data)
			{
				if (a->next->data < a->prev->data)
					ra(stack_a);
				else
					sa(stack_a);
			}
			else
				rra(stack_a);
		}
		else
		{
			if (a->data < a->next->data)
			{
				if (a->next->data < a->prev->data)
					return ;
				else
					dd_sort(stack_a, stack_b);
			}
			else
			{
				sa(stack_a);
				if (a->next->data < a->prev->data)
					rra(stack_a);
				else
					ra(stack_a);
			}
		}
	}
	if (b != 0)
	{
		pa(stack_a, stack_b);
		dd_sort(stack_a, stack_b);
	}
}

int	ft_max(t_list *a)
{
	int		max;
	t_list	*cur;
	
	cur = a;
	max = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (max < cur->next->data)
			max = cur->next->data;
		cur = cur->next;
	}
	return (max);
}

int	sort_three_a(t_list *stack)
{
	if (stack->next->data < stack->next->next->data)
	{
		if (stack->data < stack->next->next->data)
			return (1);
		else
			return (0);
	}
	else
	{
		if (stack->data < stack->next->next->data)
		{
			rra(stack);
			sa(stack);
			return (1);
		}
		else
		{
			rra(stack);
			return (1);
		}
	}
	return (0);
}

int	sort_three_b(t_list *stack)
{
	if (stack->next->data < stack->next->next->data)
	{
		if (stack->data < stack->next->next->data)
		{
			sa(stack);
			return (1);
		}
		else
		{
			ra(stack);
			return (1);
		}
	}
	else
	{
		if (stack->data > stack->next->next->data)
		{
			sa(stack);
			rra(stack);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}	

int	sort_three(t_list *stack)
{
	if (stack && stack->next && stack->next->next)
	{
		if (stack->data < stack->next->data)
			return (sort_three_a(stack));
		else
			return (sort_three_b(stack));
	}
	return (0);
}

int	next_min(t_list *a, int repeat, int min)
{
	t_list	*cur;
	int		new_min;

	cur = a;
	new_min = min + 1;
	if (repeat == 0)
		return (min);
	else if (repeat > 0)
	{
		while (cur != 0 && cur->next != 0)
		{
			if (new_min > min && new_min >= cur->data)
				new_min = cur->data;
			cur = cur->next;
		}
		return (next_min(a, repeat - 1, new_min));
	}
	else
		return (2147483647);
}

int	ft_min(t_list *a, int repeat)
{
	int		min;
	t_list	*cur;
	
	cur = a;
	min = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	if (repeat > 0)
		return (next_min(a, repeat, min));
	else
		return (min);
}

int	ft_mid(int ac, t_list *a)
{
	int		mid_min;
	int		x;

	mid_min = 0;
	x = (ac - 1) / 2;
	mid_min = ft_min(a, x);
	if (mid_min == 2147483647)
		return (msg(4), 0);
	else
		return (mid_min);
}

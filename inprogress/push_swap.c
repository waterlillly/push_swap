/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:08:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/17 20:23:50 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, int value)
{
	t_list	*node;
	t_list	*s;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
	node->prev = NULL;
	if (!stack)
	{
		node->next = NULL;
		stack = &node;
	}
	else
	{
		s = *stack;
		node->next = s;
		s->prev = node;
		stack = &node;
	}
}

void	input_args(char **av, t_list **stack_a)
{
	int		i;
	t_list	*a;

	i = 1;
	a = *stack_a;
	if (presorted(av, i))
		return ;
	while (av[i])
	{
		add_node(stack_a, ft_atoi(av[i]));
		i++;
	}
	stack_a = &a;
}

void	input_split(char **av, t_list **stack_a)
{
	int		i;
	char	**input;
	t_list  *a;

	i = 0;
	input = NULL;
	input = ft_split(av[1], ' ');
	a = *stack_a;
	if (presorted(input, i))
	{
		ft_free(input);
		return ;
	}
	while (input[i])
	{
		add_node(stack_a, ft_atoi(input[i]));
		i++;
	}
	stack_a = &a;
	ft_free(input);
}

void	parse_arguments(int ac, char **av, t_list **stack)
{	
	if (ac < 2)
		return ;
	else if (ac == 2)
		input_split(av, stack);
	else if (ac > 2)
		input_args(av, stack);
}

int	make_b_three(t_list **stack_a, t_list **stack_b)
{
	int		x;
	int		y;
	t_list	*b;

	x = 0;
	y = 0;
	b = *stack_b;
	while (b && b->next)
	{
		x++;
		b = b->next;
	}
	while (x < 3)
	{
		y += pb(stack_a, stack_b);
		x++;
	}
	return (y);
}

int	sort_more(t_list **stack_a, int elements)
{
	t_list	**stack_b;
	t_list	*a;
	int		c;

	stack_b = NULL;
	a = *stack_a;
	c = 0;
	if (elements == 4)
	{
		while (a->data != find_min(stack_a))
			c += ra(stack_a);
		c += pb(stack_a, stack_b);
		c += sort_three(stack_a);
		c += pa(stack_a, stack_b);
	}
	else
	{
		while (!is_sorted(stack_a))
		{
			c += ra(stack_a);
			c += make_b_three(stack_a, stack_b);
			c += sort_three(stack_b);
			c += pa(stack_a, stack_b);
			c += pa(stack_a, stack_b);
			c += pa(stack_a, stack_b);
		}
	}
	stack_a = &a;
	return (c);
}

int	sort(t_list **stack_a, int counter)
{
	t_list	*a;
	int		elements;

	if (!stack_a)
		return (0);
	elements = 0;
	a = *stack_a;
	elements = stack_size(stack_a);
	if (elements == 3)
		counter += sort_three(stack_a);
	else
		counter += sort_more(stack_a, elements);
	stack_a = &a;
	return (counter);
}

int	sort_three_a(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (s->next->data < s->next->next->data)
		return (x);
	else
	{
		if (s->data < s->next->next->data)
		{
			x += rra(stack);
			x += sa(stack);
		}
		else
			x += rra(stack);
	}
	return (x);
}

int	sort_three_b(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (s->next->data < s->next->next->data)
	{
		if (s->data < s->next->next->data)
			x += sa(stack);
		else
			x += ra(stack);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			x += sa(stack);
			x += rra(stack);
		}
		else
			return (x);
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
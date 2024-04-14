/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:08:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/14 23:21:13 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_list **stack, t_list *new_node)
{
	t_list	*last;
	t_list	*s;

	if (!new_node)
		return ;
	s = *stack;
	if (!stack)
		s = new_node;
	else
	{
		last = s->prev;
		new_node->next = s;
		new_node->prev = last;
		last->next = new_node;
		s->prev = new_node;
	}
	stack = &s;
}

void	input_args(int ac, char **av, t_list **stack_a)
{
	int		i;
	t_list  *a;

	i = 1;
	a = *stack_a;
	if (presorted(av, i))
		return ;
	while (i < ac)
	{
		if (!valid(av[i]))
		{
			ft_printf("error: invalid input");
			return ;
		}
		add_node(stack_a, create_node(ft_atoi(av[i])));
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
	input = ft_split(av[1], ' ');
	a = *stack_a;
	if (presorted(input, i))
	{
		ft_free(input);
		return ;
	}
	while (input[i])
	{
		if (!valid(input[i]))
		{
			ft_free(input);
			ft_printf("error: invalid input");
			return ;
		}
		add_node(stack_a, create_node(ft_atoi(input[i])));
		i++;
	}
	stack_a = &a;
	ft_free(input);
}

void	parse_arguments(int ac, char **av, t_list **stack)
{
	t_list  *a;
	
	a = *stack;
	if (ac < 2)
		return ;
	else if (ac == 2)
		input_split(av, stack);
	else if (ac > 2)
		input_args(ac, av, stack);
	stack = &a;
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

int	sort(t_list **stack_a, t_list **stack_b, int counter)
{
	t_list	*a;
	int		elements;

	a = *stack_a;
	elements = stack_size(stack_a);
	if (elements == 3)
		counter += sort_three(stack_a);
	else if (elements == 4)
	{
		while (a->data != find_min(stack_a))
			counter += ra(stack_a);
		counter += pb(stack_a, stack_b);
		counter += sort_three(stack_a);
		counter += pa(stack_a, stack_b);
	}
	else
	{
		while (!is_sorted(stack_a))
		{
			counter += ra(stack_a);
			counter += make_b_three(stack_a, stack_b);
			counter += sort_three(stack_b);
			counter += pa(stack_a, stack_b);
			counter += pa(stack_a, stack_b);
			counter += pa(stack_a, stack_b);
		}
	}
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
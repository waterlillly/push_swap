/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:08:51 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/04 20:08:56 by lbaumeis         ###   ########.fr       */
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
	node->next = node;
	node->prev = node;
	return (node);
}

void	add_node(t_list **stack, t_list *new_node)
{
	t_list	*last;

	if (!stack || !new_node)
		return ;
	if (*stack)
	{
		last = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = last;
		last->next = new_node;
		(*stack)->prev = new_node;
	}
	else
		*stack = new_node;
}

t_list	*input_args(int ac, char **av, t_list *stack_a)
{
	int	i;

	i = 1;
	if (presorted(av, i))
		return (NULL);
	while (i < ac)
	{
		if (!valid(av[i]))
			return (ft_printf("error: invalid input"), NULL);
		add_node(&stack_a, create_node(ft_atoi(av[i])));
		i++;
	}
	return (stack_a);
}

t_list	*input_split(char **av, t_list *stack_a)
{
	int		i;
	char	**input;

	i = 0;
	input = ft_split(av[1], ' ');
	if (presorted(input, i))
		return (ft_free(input), NULL);
	while (input[i] != NULL)
	{
		if (!valid(input[i]))
			return (ft_free(input), ft_printf("error: invalid input"), NULL);
		add_node(&stack_a, create_node(ft_atoi(input[i])));
		i++;
	}
	return (ft_free(input), stack_a);
}

t_list	*parse_arguments(int ac, char **av)
{
	t_list	*stack_a;
	
	stack_a = NULL;
	if (ac < 2)
		return (NULL);
	else if (ac == 2)
		return (input_split(av, stack_a));
	else if (ac > 2)
		return (input_args(ac, av, stack_a));
	else
		return (NULL);
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
	elements = stack_size(a);
	if (elements == 3)
		counter += sort_three(stack_a);
	else if (elements == 4)
	{
		while (a->data != find_min(a))
			counter += ra(stack_a);
		counter += pb(stack_a, stack_b);
		counter += sort_three(stack_a);
		counter += pa(stack_a, stack_b);
	}
	else
	{
		while (!is_sorted(a))
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
			x += sa(s);
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
			x += sa(s);
		else
			x += ra(stack);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			x += sa(s);
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
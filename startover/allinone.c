/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allinone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/18 21:59:25 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_list *stack)
{
	t_list	*s;

	s = stack;
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

void	add(t_list **head, int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
	node->prev = NULL;
	if (*head)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	else
		node->next = NULL;
	*head = node;
}

int	arr_len(char **input)
{
	int	x;

	x = 0;
	if (!input)
		return (0);
	while (input[x])
		x++;
	return (x);
}

int	check_doubles(char **input, int x)
{
	int	y;
	int	z;

	y = 0;
	z = x + 1;
	while (input[x])
	{
		y = ft_atoi(input[x]);
		while (input[z])
		{
			if (y == ft_atoi(input[z]))
				return (0);
			z++;
		}
		x++;
		z = x + 1;
	}
	return (1);
}

void	fill_stack(int ac, char **av, t_list **head)
{
	char	**input;
	int		x;
	int		y;

	input = NULL;
	x = 0;
	if (ac > 2)
	{
		x = 1;
		input = av;
	}
	else if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		if (!input)
			return ;
	}
	if (!check_doubles(input, x))
	{
		ft_printf("doubles in input\n");
		return ;
	}
	y = arr_len(input) - 1;
	while (input[y] && y >= x)
	{
		add(head, ft_atoi(input[y]));
		y--;
	}
}

int	ft_find(char *str, int c)
{
	int	i;
	int	occ;

	i = 0;
	occ = 0;
	while (str[i])
	{
		if (str[i] == c)
			occ++;
		i++;
	}
	if (c == '\0')
		return (1);
	return (occ);
}

int	valid_arg(char **av)
{
	int		x;
	char	*in;

	x = 0;
	in = av[1];
	if (ft_find(in, ' ') == 0)
	{
		if (ft_atoi(in) >= INT_MIN && ft_atoi(in) <= INT_MAX)
			return (ft_printf("only one number\n"), 0);
		return (ft_printf("not valid\n"), 0);
	}
	if (in[0] == '-')
		x++;
	else if (in[0] == ' ')
		return (0);
	while (in[x])
	{
		if (in[x] == '-' && ft_isdigit(in[x + 1]))
			x++;
		while (in[x] && ft_isdigit(in[x]))
			x++;
		if (in[x] == ' ' && (in[x + 1] == '-' || ft_isdigit(in[x + 1])))
			x++;
	}
	return (1);
}

/*push_swap.c from inprogress*/
int	make_b_three(t_list **stack_a, t_list **stack_b)
{
	int		x;
	int		y;
	t_list	*b;

	x = 0;
	y = 0;
	b = *stack_b;
	while (b)
	{
		x++;
		b = b->next;
	}
	while (x < 3)
	{
		y += pb(stack_a, stack_b);
		x++;
	}
	*stack_b = b;
	return (y);
}

int	sort_more(t_list **stack_a, int elements)
{
	t_list	*b;
	t_list	*a;
	int		c;

	b = NULL;
	a = *stack_a;
	c = 0;
	if (elements == 4)
	{
		while (a->data != find_min(a))
			c += ra(stack_a);
		c += pb(stack_a, &b);
		c += sort_three(stack_a);
		c += pa(stack_a, &b);
	}
	else
	{
		while (!is_sorted(a))
		{
			c += ra(stack_a);
			c += make_b_three(stack_a, &b);
			c += sort_three(&b);
			c += pa(stack_a, &b);
			c += pa(stack_a, &b);
			c += pa(stack_a, &b);
		}
	}
	*stack_a = a;
	return (c);
}

int	sort(t_list **stack_a)
{
	t_list	*a;
	int		counter;
	int		elements;

	a = *stack_a;
	counter = 0;
	elements = 0;
	if (!a)
		return (0);
	elements = stack_size(a);
	if (elements == 3)
		counter = sort_three(stack_a);
	else
		counter = sort_more(stack_a, elements);
	*stack_a = a;
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
			x = rra(stack);
			x = sa(stack);
		}
		else
			x = rra(stack);
	}
	*stack = s;
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
			x = sa(stack);
		else
			x = ra(stack);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			x = sa(stack);
			x = rra(stack);
		}
	}
	*stack = s;
	return (x);
}

int	sort_three(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (!s || !s->next || !s->next->next)
		return (0);
	if (s->data < s->next->data)
		x = sort_three_a(stack);
	else
		x = sort_three_b(stack);
	*stack = s;
	return (x);
}

int	stack_size(t_list *stack)
{
	int		x;
	t_list  *s;

	s = stack;
	if (!s)
		return (-1);
	x = 0;
	while (s)
	{
		x++;
		s = s->next;
	}
	return (x);
}

int	find_min(t_list *stack)
{
	int	min;
	t_list  *s;

	min = INT_MAX;
	s = stack;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;
	t_list  *s;

	max = INT_MIN;
	s = stack;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

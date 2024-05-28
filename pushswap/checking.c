/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:17:18 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 15:04:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_find(in, ' ') == 0 && (ft_isdigit(in[ft_strlen(in)])
					&& (ft_atoi(in) >= INT_MIN && ft_atoi(in) <= INT_MAX)))
		return (ft_printf("error: invalid\n"), 0);
	while (in[x])
	{
		if (in[x] == '-' && ft_isdigit(in[x + 1]))
			x++;
		while (in[x] && ft_isdigit(in[x]))
			x++;
		if (in[x] == ' ' && x != 0)
		{
			x++;
			if (ft_isdigit(in[x]) || (in[x] == '-' && ft_isdigit(in[x + 1])))
				x++;
		}
		if (((in[x - 1] == ' ' || in[x + 1] == '\0' || x == 0) && in[x] == ' ')
				|| (in[x] == '-' && !(ft_isdigit(in[x + 1]))))
			return (ft_printf("error: invalid\n"), 0);
	}
	return (1);
}

int	locate(t_list *stack, int data)
{
	int	x;
	t_list	*s;

	x = 0;
	s = stack;
	while (s && s->data != data)
	{
		x++;
		s = s->next;
	}
	if (s->data == data)
		return (x);
	return (-1);
}

int	rot_until(t_list **stack, int data)
{
	int		loc;
	t_list	*s;
	int		x;

	loc = locate(*stack, data);
	x = 0;
	if (loc == -1)
		return (-1);
	s = *stack;
	while (s->data != data)
	{
		if (loc <= stack_size(s) / 2)
			x += ra(&s);
		else
			x += rra(&s);
	}
	*stack = s;
	return (x);
}

int	rot_double(t_list **stack_a, t_list **stack_b, int data_a, int data_b)
{
	int	loc_a;
	int	loc_b;
	t_list	*a;
	t_list	*b;

	loc_a = locate(*stack_a, data_a);
	loc_b = locate(*stack_b, data_b);
	if (loc_a == -1 || loc_b == -1)
		return (-1);
	a = *stack_a;
	b = *stack_b;
	while (a->data != data_a && b->data != data_b)
	{
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
	*stack_a = a;
	*stack_b = b;
	return (1);
}

void	show(t_list *stack)
{
	t_list	*s;

	s = stack;
	while (s)
	{
		ft_printf("%d\n", s->data);
		s = s->next;
	}
}

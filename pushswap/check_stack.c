/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:17:18 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 12:48:54 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (0);
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
			return (0);
	}
	return (1);
}

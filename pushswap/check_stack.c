/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:17:18 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 17:42:37 by lbaumeis         ###   ########.fr       */
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
	t_list	*s;

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

int	ft_check_arg(int x, char **input)
{
	char	*tmp;

	while (input[x] != NULL)
	{
		tmp = ft_itoa(ft_atoi(input[x]));
		if (!tmp)
			return (false);
		if (ft_strncmp(tmp, input[x], ft_strlen(input[x])) == 0)
		{
			free(tmp);
			x++;
		}
		else
			return (free(tmp), false);
	}
	return (true);
}

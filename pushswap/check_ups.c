/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:14 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/26 23:30:36 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(t_list *s)
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

void msg(int nbr)
{
	char *msg[9];

	msg[0] = "Error: malloc";
	msg[1] = "Error: wrong input";
	msg[2] = "Error: doubles in input";
	msg[3] = "Error: not sorted";
	msg[4] = "Error: unclear||->in function";
	msg[5] = "Error: filling stack";
	msg[6] = "sorted! :)";
	msg[7] = "Error: unable to sort";
	msg[8] = "Error: in split-function";
	ft_printf("%s\n", msg[nbr]);
}

int	arr_len(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
		x++;
	return (x);
}

int check_sort(t_list *s)
{
	if (!s)
		return (0);
	while (s && s->next && s->data < s->next->data)
		s = s->next;
	if (s->next == 0)
		return (1);
	return (0);
}

char	**get_split_input(char **av)
{
	char	**s;
	int		x;
	int		y;

	s = NULL;
	x = 0;
	y = 0;
	while (av[1][x])
	{
		if (av[1][x] == ' ')
			y++;
		x++;
	}
	if (y == 0)
		return (ft_printf("only one number\n"), NULL);
	else
	{
		//s = (char **)malloc(sizeof(char *) * (y + 2));
		//if (!s)
			//return (0);
		s = ft_split(av[1], ' ');
		if (!s)
			return (0);
		return (s);		
	}
	return (NULL);
}

char	**get_input(int ac, char **av)
{
	int		x;
	int		y;
	char	**s;
	char	*next;

	x = 1;
	y = 0;
	next = NULL;
	s = (char **)malloc(sizeof(char *) * ac);
	if (!s)
		return (0);
	while (av[x])
	{
		next = ft_strdup(av[x]);
		if (!next)
			return (0);
		s[y] = next;
		next = NULL;
		x++;
		y++;
	}
	s[y] = 0;
	if (!s || y != (ac - 1))
		return (free(s), free(next), NULL);
	return (free(next), s);
}

/*
int	**convert_check(char **s)
{
	int	x;
	int	**arr;

	x = 0;
	while (s[x])
		x++;
	arr = (int **)malloc(sizeof(int *) * (x + 1));
	if (!arr)
		return (0);
	x = 0;
	while (s[x] && arr[x])
	{
		*arr[x] = ft_atoi(s[x]);
		x++;
	}
	arr[x] = 0;
	return (free(s), arr);
}
*/

int	check_doubles(char **arr)
{
	int	x;
	int	y;
	int	z;

	x = 1;
	y = 0;
	z = 0;
	while (arr[x])
	{
		y = ft_atoi(arr[x]);
		z = x;
		x--;
		while (x >= 0)
		{
			if (y == ft_atoi(arr[x]))
				return (ft_printf("doubles in input\n"), free(arr), 0);
			x--;
		}
		x = z + 1;
	}
	return (1);
}

int	presorted(char **arr)
{
	int	x;
	
	x = 0;
	while (arr[x] && arr[x + 1])
	{
		if (ft_atoi(arr[x]) < ft_atoi(arr[x + 1]))
			x++;
		else
			return (0);
	}
	return (ft_printf("no need to sort\n"), 1);
}

char **check_input(int ac, char **av)
{
	char	**arr;

	arr = NULL;
	if (ac < 2 || (ac == 2 && av[1][0] == 0))
		return (NULL);
	else if (ac == 2)
	{
		arr = get_split_input(av);
		if (!arr)
			return (NULL);
	}
	else
	{
		arr = get_input(ac, av);
		if (!arr)
			return (NULL);
	}
	if (presorted(arr))
		return (NULL);
	else if (check_doubles(arr))
		return (arr);
	else
		return (free(arr), NULL);
}

/*
int check_doubles(int ac, int pos, t_list **stack)
{
	t_list *s;
	int value;
	int x;

	s = *stack;
	value = 0;
	x = 0;
	while (x <= pos && pos < ac)
	{
		s = s->next;
		x++;
	}
	value = s->prev->data;
	if ((pos == ac - 1) && (s->data != value))
		return (1);
	else
	{
		while (s != 0 && s->next != 0 && s->data != value)
			s = s->next;
		if (s->data == value && s != 0 && s->next != 0)
			return (0);
		else if (s->next == 0)
			return (check_doubles(ac, pos + 1, stack));
	}
	return (0);
}
*/

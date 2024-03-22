/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:14 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/22 01:51:58 by lbaumeis         ###   ########.fr       */
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

int	arr_len(int *arr)
{
	int	x;
	
	x = 0;
	while (arr[x])
		x++;
	return (x);
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

int	*get_split_input(int ac, char **av)
{
	char	**s;
	int		x;
	int		y;

	s = NULL;
	x = 0;
	y = 0;
	if (ac == 2)
	{
		while (av[1][x])
		{
			if (av[1][x] == ' ')
				y++;
			x++;
		}
		if (y == 0)
			return (ft_printf("only one number\n"), NULL);
		else if (av[1] == NULL)
			return (ft_printf("empty input\n"), NULL);
		else
		{
			s = ft_split(av[1], ' ');
			if (!s)
				return (0);
			return (convert_check(s));		
		}
	}
	return (NULL);
}

int	*get_input(int ac, char **av)
{
	int		x;
	char	**s;

	s = NULL;
	x = 1;
	if (ac > 2)
	{
		s = (char **)malloc(sizeof(char *) * ac);
		if (!s)
			return (0);
		while (av[x])
		{
			*s = av[x];
			x++;
		}
		*s = NULL;
		return (convert_check(s));
	}
	return (0);
}

int	*convert_check(char **s)
{
	int	x;
	int	*arr;

	x = 0;
	arr = NULL;
	while (s[x])
		x++;
	arr = (int *)malloc(sizeof(int) * (x + 1));
	if (!arr)
		return (NULL);
	x = 0;
	while (s[x])
	{
		arr[x] = ft_atoi(s[x]);
		if (!arr[x])
			return (ft_printf("invalid input\n"), free(arr), NULL);
		x++;
	}
	return (free(s), arr);
}

int	check_doubles(int *arr)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (arr[x] && arr[x + 1])
	{
		y = arr[x];
		z = x + 1;
		while (arr[z] && y != arr[z])
			z++;
		if (y == arr[z])
			return (ft_printf("doubles in input\n"), 0);
		else
			x++;
	}
	if (x == arr_len(arr))
		return (1);
	else
		return (0);
}

int	presorted(int *arr)
{
	int	x;
	
	x = 0;
	while (*arr)
	{
		while (arr[x] < arr[x + 1])
		{
			x++;
			if (x == arr_len(arr))
				return (ft_printf("no need to sort\n"), 1);
		}
	}
	return (0);
}

int *check_input(int ac, char **av)
{
	int		*arr;

	arr = NULL;
	if (ac < 2 || (ac == 2 && av[1][0] == 0))
		return (NULL);
	else if (ac == 2)
	{
		arr = get_split_input(ac, av);
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
		return (free(arr), NULL);
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

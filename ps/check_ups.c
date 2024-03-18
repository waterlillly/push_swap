/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:25:00 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/18 18:09:46 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_free(t_list *s)
{
	while (s != 0 && s->next != 0)
		s = s->next;
	while (s->prev != 0)
	{
		free(s);
		s = s->prev;
	}
	s = 0;
	free(s);
}

void msg(int nbr)
{
	char *msg[9];

	msg[0] = "Error: malloc\n";
	msg[1] = "Error: wrong input\n";
	msg[2] = "Error: doubles in input\n";
	msg[3] = "Error: not sorted\n";
	msg[4] = "Error: invalid\n";
	msg[5] = "Error: filling stack\n";
	msg[6] = "sorted! :)\n";
	msg[7] = "Error: unable to sort\n";
	msg[8] = "Error: in split-function\n";
	ft_printf("%s", msg[nbr]);
}

int check_sort(t_list *stack)
{
	t_list *a;

	if (!stack)
		return (0);
	a = stack;
	while (a && a->next && a->data < a->next->data)
	{
		a = a->next;
		if (a->next == 0)
			return (1);
	}
	return (0);
}

int is_sorted(int ac, char **av)
{
	int x;
	int	y;

	x = 1;
	y = 0;
	if (check_input(ac, av) == 1)
	{
		while (**av && x < ac && ft_atoi(av[x]) < ft_atoi(av[x + 1]))
			x++;
		if (ac == 2)
			y = ft_arr_len(av) + 1;
		else
			y = ac;
		if (x == y)
			return (msg(6), 1);
	}
	return (msg(4), 0);
}

int	check_doubles(int ac, char **av)
{
	int	x;
	int	y;
	int	z;

	x = 1;
	y = 0;
	z = 2;
	while (**av && x < ac)
	{
		y = ft_atoi(av[x]);
	//	if (y > 2147483647 || y < -2147483648)
	//		return (0);
		while (**av && z < ac)
		{
			if (y == ft_atoi(av[z]))
				return (msg(2), 0);
			z++;
		}
		x++;
		z = x + 1;
	}
	return (1);
}

int check_input(int ac, char **av)//check doubles in here
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (**av && x < ac)
	{
		while (av[x][y])
		{
			if ((av[x][y] >= '0') && av[x][y] <= '9')
				y++;
			else
				return (0);
		}
		y = 0;
		x++;
	}
	if (x == ac && check_doubles(ac, av) == 1)
		return (1);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:14 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/18 16:30:58 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(t_list **l)
{
	t_list *list;

	list = NULL;
	list = *l;
	while (list != 0 && list->next != 0)
		list = list->next;
	while (list->prev != 0)
	{
		free(list);
		list = list->prev;
	}
	list = 0;
	free(list);
	l = 0;
	free(l);
}

void msg(int nbr)
{
	char *msg[9];

	msg[0] = "Error: malloc\n";
	msg[1] = "Error: wrong input\n";
	msg[2] = "Error: doubles in input\n";
	msg[3] = "Error: not sorted\n";
	msg[4] = "Error: unclear||->in function\n";
	msg[5] = "Error: filling stack\n";
	msg[6] = "sorted! :)\n";
	msg[7] = "Error: unable to sort\n";
	msg[8] = "Error: in split-function\n";
	ft_printf("%s", msg[nbr]);
}

int check_sort(t_list **stack)
{
	t_list *a;

	if (!stack)
		return (0);
	a = NULL;
	a = *stack;
	while (a != 0 && a->next != 0 && a->data < a->next->data)
		a = a->next;
	if (a->data > a->next->data && a->next != 0)
		return (0);
	return (1);
}

int is_sorted(int ac, char **av)
{
	int x;

	x = 1;
	while (**av && x < ac && ft_atoi(av[x]) < ft_atoi(av[x + 1]))
		x++;
	if (x == ac)
		return (msg(6), 0);
	else if (check_input(ac, av) == 1)
		return (1);
	return (msg(4), 0);
}

int	check_doubles(int ac, char **av)
{
	int	x;
	long int	y;
	int	z;

	x = 1;
	y = 0;
	z = 2;
	while (**av && x < ac)
	{
		y = ft_atoi(av[x]);
		if (y > 2147483647 || y < -2147483648)
			return (0);
		while (**av && z < ac)
		{
			if ((int)y == ft_atoi(av[z]))
				return (msg(2), 0);
			z++;
		}
		x++;
		z = x + 1;
	}
	return (1);
}

int check_input(int ac, char **av)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (**av && x < ac)
	{
		while (av[x][y])
		{
			if (ft_isdigit(av[x][y]))
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

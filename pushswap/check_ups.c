/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:09:14 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/13 06:20:47 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **a, t_list **b)
{
	t_list	*alist;
	t_list	*blist;

	alist = *a;
	blist = *b;
	while (alist != 0 && alist->next != 0 && blist != 0 && blist->next != 0)
	{
		alist = alist->next;
		blist = blist->next;
	}
	while (alist->prev != 0 && blist->prev != 0)
	{
		free(alist);
		alist = alist->prev;
		free(blist);
		blist = blist->prev;
	}
	alist = 0;
	blist = 0;
	a = 0;
	b = 0;
	free(alist);
	free(blist);
	free(a);
	free(b);
}

void	error(int nbr)
{
	char	*err[5];
	
	err[0] = "Error: malloc\n";
	err[1] = "Error: wrong input\n";
	err[2] = "Error: doubles in input\n";
	err[3] = "Error: not sorted\n";
	err[4] = "Error: unclear||->in function\n";
	if (nbr == 33)
		write(1, "already sorted :)", 17);
	else
		write(2, &(err[nbr]), ft_strlen(err[nbr]));
}

int	check_doubles(int ac, int pos, t_list **stack)
{
	t_list	*s;
	int		value;
	int		x;

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

int	check_sort(t_list **stack_a)
{
	t_list	*a;
	
	a = *stack_a;
	while (a != 0 && a->next != 0 && a->data < a->next->data)
		a = a->next;
	if (a->data > a->next->data && a->next != 0)
		return (0);
	return (1);
}

int	check_input(int ac, char **av)
{
	int		x;
	int		y;

	x = 1;
	y = 0;
	if (ac <= 2)
		return (0);
	while (*av[x])
	{
		while (av[x][y] && y != -1)
		{
			if (ft_isdigit(av[x][y]) == 1)
				y++;
			else
				return (0);
		}
		x++;
	}
	return (1);
}

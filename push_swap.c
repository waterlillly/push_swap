/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:04:09 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/09 15:01:24 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char c)
{
	ft_printf("Error: ");
	if (c == 'm')
		ft_printf("malloc\n");
	else if (c == 'i')
		ft_printf("wrong input\n");
	else if (c == 'd')
		ft_printf("doubles in input\n");
	else if (c == 's')
		ft_printf("not sorted\n");
	else if (c == 'w')
		ft_printf("unclear||->in function\n");
	return (-1);
}

int	check_sort(t_list **a)
{
	while (a != 0 && a->next != 0 && a->data < a->next->data)
		a = a->next;
	if ((a->data > a->next->data || a->data == a->next->data) && a->next != 0)
		return (error('i'));
	return (0);
}

t_list	*create_node(int value)
{
	t_list	*node;
	
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->data = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*input(int ac, char **av, t_list *stack)
{
	int		x;
	int		y;
	t_list	*node;
	
	x = 0;
	y = 0;
	node = NULL;
	while (av[x][y])
	{
		while (av[x][y] && ft_isdigit(av[x][y]))
			y++;
		if (av[x][y] == '\0')
		{
			node = create_node(ft_atoi(av[x]));
			if(!node)
				return (0);
			node->prev = stack;
			stack->next = node;
			stack = stack->next;
		}
		x++;
		y = 0;
	}
	stack->next = NULL;
	return (stack);
}

int	max(t_list **a)
{
	int		x;
	t_list	*cur;
	
	x = cur->data;
	cur = &*a;
	while (cur != 0 && cur->next != 0)
	{
		if (x < cur->next->data)
			x = cur->next->data;
		cur = cur->next;
	}
	return (max);
}

int	next_min(t_list **a, int repeat, int min)
{
	t_list	*cur;
	int		new_min;

	cur = &(*a);
	new_min = min + 1;
	if (repeat == 0)
		return (min);
	else if (repeat > 0)
	{
		while (cur != 0 && cur->next != 0)
		{
			if (new_min > min && new_min >= cur->data)
				new_min = cur->data;
			cur = cur->next;
		}
		return (next_min(a, repeat - 1, new_min));
	}
	else
		return (2147483647);
}

int	min(t_list **a, int repeat)
{
	int		min;
	t_list	*cur;
	
	cur = &*a;
	min = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	if (repeat > 0)
		return (next_min(a, repeat, min));
	else
		return (min);
}

int	mid(int ac, t_list **a)
{
	int		mid_min;
	int		x;

	mid_min = 0;
	x = (ac - 1) / 2;
	mid_min = min(a, x);
	if (mid_min == 2147483647)
		return (error('w'));
	else
		return (mid_min);
}

void	ft_free(t_list **a, t_list **b)
{
	t_list	*alist;
	t_list	*blist;

	alist = &(*a);
	blist = &(*b);
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

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	int		x;
	
	a = NULL;
	b = NULL;
	x = 1;
	if (ac == 1 || ac == 2)
		return (error('i'));
	else if (ac == 0)
		return (0);
	a = (t_list **)malloc(sizeof(t_list *) * (ac - 1));
	if (!a)
		return (error('m'));
	b = (t_list **)malloc(sizeof(t_list *) * (ac - 1));
	if (!b)
		return (error('m'));
	a = input(ac, av, a);
	if (!a)
		return (error('w'));
	sort(a, b);
	if (check_sort(a) == 0)
		ft_free(a, b);
	return (0);
}

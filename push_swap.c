/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:48:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/03 07:46:31 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	check_back(t_list *cur)
{
	long int	x;

	x = cur->data;
	while (cur != 0 && cur->prev != 0)
	{
		if (cur->prev->data == x)
			return (-1);
		cur = cur->prev;
	}
	if (cur->prev == 0)
		return (0);
}
*/

int	len(t_list *x)
{
	int	i;
	
	i = 0;
	while (x != 0)
	{
		i++;
		x = x->next;
	}
	return (i);
}
/*
long int	max(t_list *x)
{
	long int	max;
	
	max = x->data;
	while (x != 0 && x->next != 0)
	{
		if (max < x->data)
			max = x->data;
		x = x->next;
	}
	return (max);
}

long int	min(t_list *x)
{
	long int	min;
	
	min = x->data;
	while (x != 0 && x->next != 0)
	{
		if (min > x->data)
			min = x->data;
		x = x->next;
	}
	return (min);
}
*/

t_list	*parse_stack(t_list *a, t_list *b, int *operations)
{
	int		middle;
	
	middle = ((len(a) / 2) + (len(a) % 2));
	while (a != 0 && a->next != 0)
	{
		if (middle > 0 && a->data > a->next->data)
		{
			pb(a, b);
			middle--;
			operations++;
		}
		if (b != 0 && a->data > b->data)
		{
			pa(a, b);
			middle++;
			operations++;
		}
		a = a->next;
	}
	while (a->prev != 0 && a->data > a->prev->data)
		a = a->prev;
	if (a->prev == 0)
		return (*operations, a);
	else
		parse_stack(a, b, &operations);
}

t_list	*push_swap(t_list *a, int *operations)
{
	t_list	*b;
	
	b->data = NULL;
	b->next = NULL;
	b->prev = NULL;
	if (a != 0 && a->next != 0)
	{
		b = parse_stack(a, b, &operations);
		if (!b)
			return (*operations, NULL);
		return (*operations, b);
	}
	return (*operations, NULL);
}

t_list	*stack_a(int x, char **input)
{
	t_list		*a;
	long int	y;
	
	y = 0;
	a->prev = NULL;
	a->next = NULL;
	while (*input[x])
	{
		if (ft_atoi(input[x]))
			y = ft_atoi(input[x]);
		else
			return (NULL);
		a->data = y;
		a = a->next;
		a->next = NULL;
		x++;
	}
	if (*input[x] == NULL)
	{
		while (*input[x])
			free(*input[x--]);
		free(input);
		return (a);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int			x;
	char		**input;
	t_list		*a;
	int			*operations;

	x = 0;
	input = NULL;
	a = NULL;
	operations = 0;
	if (ac < 2)
		return (-1);
	else if (ac == 2)
		input = ft_split(av[1], ' ');
	else
	{
		input = av;
		x = 1;
	}
	if (stack_a(x, input) == NULL)
		return (-1);
	a = push_swap(a, &operations);
	if (operations == -1)
		return (-1);
	return (0);
}

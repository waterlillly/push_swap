/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:48:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/04 16:23:00 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort(t_list *a, t_list *b)
{
	while (a != 0 && a->next != 0)
	{
		if (b == 0)
			pb(a, b);
		if (b->next == 0)
			pb(a, b);
		//if (a->data < b->data)
		//{
			//pb(a, b);
		while (b->data < b->next->data)
		{
			sb(b);
			rb(b);
		}
		//}
		//if (a->data > b->data)
			//pb(a, b);
	}
	if (a == 0 && (b->data > b->next->data))
		return (b);
	else
		return (sort(b, a));
	//{
		//while (b != 0)
			//pa(a, b);
	//}
	//return (a);
}

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

t_list	*parse_stack(t_list *a, t_list *b)
{
	int		middle;
	
	middle = ((len(a) / 2) + (len(a) % 2));
	while (a != 0 && a->next != 0)
	{
		if (middle > 0 && a->data > a->next->data)
		{
			pb(a, b);
			middle--;
		}
		if (b != 0 && a->data > b->data)
		{
			pa(a, b);
			middle++;
		}
		a = a->next;
	}
	while (a->prev != 0 && a->data > a->prev->data)
		a = a->prev;
	if (a->prev == 0)
		return (a);
	else
		return (parse_stack(a, b));
}
*/

t_list	*push_swap(t_list *a)
{
	t_list	*b;
	
	b = NULL;
	if (a != 0 && a->next != 0)
	{
		b = sort(a, b);
		if (!b)
			return (NULL);
		return (b);
	}
	return (NULL);
}

t_list	*stack_a(int x, char **input)
{
	t_list		*a;
	long int	y;
	
	y = 0;
	a = NULL;
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
	if (*input == NULL)
	{
		while (*input--)
			free(*input);
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

	x = 0;
	input = NULL;
	a = NULL;
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
	a = push_swap(a);
	return (0);
}

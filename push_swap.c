/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:48:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/05 15:16:52 by lbaumeis         ###   ########.fr       */
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
	return (-1);
}

t_list	*sort(t_list *a, t_list *b)
{
	while (a != 0 && a->next != 0)
	{
		if (b == 0)
			pb(a, b);
		if (b->next == 0)
			pb(a, b);
		while (b->data > b->next->data)
		{
			sb(b);
			rb(b);
		}
	}
	if (a == 0 && (b->data < b->next->data))
		return (b);
	else
		return (sort(b, a));
}

t_list	*push_swap(t_list *a)
{
	t_list	*b;
	
	b = (t_list *)malloc(sizeof(t_list));
	if (!b)
	{
		ft_printf("Error: malloc\n");
		return (0);
	}
	if (a != 0 && a->next != 0)
	{
		b = sort(a, b);
		if (!b)
		{
			ft_printf("Error: return of sort\n");
			return (0);
		}
	}
	return (b);
}

t_list	*stack_a(char **input, t_list *a)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (*input[x])
	{
		y = ft_atoi((const char *)input[x]);
		a->data = y;
		a = a->next;
		a->next = NULL;
		x++;
	}
	while (x >= 0)
		free(input[x--]);
	input = NULL;
	free(input);
	if (!a)
	{
		ft_printf("Error: creating stack_a\n");
		return (0);
	}
	return (push_swap(a));
}

int	check_sort(t_list *a)
{
	while (a != 0 && a->next != 0)
	{
		if (a->data > a->next->data)
			return (error('i'));
		a = a->next;
	}
	return (0);
}

int	check_input(char **input)
{
	int		x;
	int		y;
	char	*z;

	x = 0;
	y = 0;
	while (*input[x])
	{
		z = input[x];
		if (x > 0)
		{
			y = x - 1;
			while (*input[y] && y >= 0)
			{
				if (z == input[y])
					return (error('d'));
				y--;
			}
		}
		x++;
	}
	return (0);
}

char	**get_input(int ac, char **av, char **input)
{
	int 	x;

	x = 0;
	if (ac == 2)
		input = ft_split(av[1], ' ');
	else
	{
		x = 1;
		while (*av[x] && x <= ac)
		{
			*input = av[x];
			x++;
		}
		input[ac - 1] = NULL;
	}
	if (check_input(input) != 0)
	{
		ft_printf("Error: wrong input\n");
		return (0);
	}
	return (input);
}

int	main(int ac, char **av)
{
	char		**input;
	t_list		*a;

	input = NULL;
	a = NULL;
	if (ac < 2)
		return (error('i'));
	input = (char **)malloc(sizeof(char *) * ac);
	if (!input)
		return (error('m'));
	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		return (error('m'));
	input = get_input(ac, av, input);
	if (!input)
	{
		ft_printf("Error: while getting input\n");
		return (0);
	}
	a = stack_a(input, a);
	if (!a)
		return (error('m'));
	if (check_sort(a) != 0)
		return (error('s'));
	return (0);
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

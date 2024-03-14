/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fillers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:48:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/11 14:45:22 by lbaumeis         ###   ########.fr       */
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

t_list	**sort(t_list **a, t_list **b)
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

int	check_int_doubles(t_list **a)
{
	int			x;
	int			y;
	int 	*nbr;

	x = 0;
	y = 0;
	nbr = (int *)&a;
	while (in[x] && ft_isdigit(in[x])
	{
		if (x > 0)
		{
			y = x - 1;
			while (in[x] && y >= 0)
			{
				if (ft_strncmp(in[y], in[x], ft_strlen(in[x]) == 0)
					return (error('d'));
				else
					y--;
			}
		}
		x++;
	}
	return (0);
}

char	**one(char **av, char **input)
{
	input = ft_split(av[1], ' ');
	if (!input)
	{
		ft_printf("Error: split\n");
		return (0);
	}
	if (input[1] == NULL)
	{
		ft_printf("Error: not enough input\n");
		return (0);
	}
	else
		return (input);
}

char	**two(int ac, char **av, char **input)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	input = (char **)malloc(sizeof(char *) * ac);
	if (!input)
	{
		ft_printf("Error: malloc\n");
		return (0);
	}
	while (av[x] && input[y] && x <= ac)
	{
		input[y] = av[x];
		x++;
		y++;
	}
	input[y] = NULL;
	return (input);
}

char	**get_input(int ac, char **av)
{
	char	**input;

	input = NULL;
	if (ac == 2)
	{
		input = one(av, input);
		if (!input)
			return (0);
	}
	else
	{
		input = two(ac, av, input);
		if (!input)
			return (0);
	}
	if (check_doubles(input) != 0)
	{
		ft_printf("Error: wrong input\n");
		return (0);
	}
	return (input);
}

t_list	*create_node(t_list **add_to, int value)
{
	t_list	*new_node;
	
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = add_to;
	*add_to->next = new_node;
	return (new_node);
}

char	**input(int ac, char **av, t_list **a)
{
	int	x;
	int	y;
	t_list	*add_node;
	
	x = 0;
	y = 0;
	add_node = NULL;
	while (*av[x])
	{
		if (ft_isdigit(*av[x]))
		{
			add_node = create_node(a, ft_atoi(*av[x]));
			if(!add_node)
				return (0);
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_list		**a;
	int			len;

	a = NULL;
	len = 0;
	if (ac < 2)
		return (-1);
	else if (ac == 2)
		len = ft_strlen(av[1]);
	else if (av > 2)
	{
		while (*av)
			len++;
	}
	a = (t_list **)malloc(sizeof(t_list *) * (len + 1));
	if (!a)
	{
		ft_printf("Error: malloc\n");
		return (0);
	}
	input = get_input(ac, av);
	if (!input)
	{
		ft_printf("Error: while getting input\n");
		return (-1);
	}
	a = stack_a(input, a);
	if (!a)
	{
		ft_printf("Error: malloc\n");
		return (0);
	}
	if (check_sort(a) != 0)
		return (error('s'));
	return (0);
}

/*
int	check_input(int ac, t_list **a)
{
	int		x;
	int		arr[ac -1];
	t_list	*cur_a;

	x = 0;
	cur_a = &(*a);
	while (cur_a!= 0 && cur_a->next != 0)
	{
		arr[] = cur_a->next;
		while (cur_a->next != 0)
		{
			if (x == cur_a->next->data)
				return (error('d'));
			else
				cur_a = cur_a->next;
		}
		while (cur_a->prev != 0)
		{
			if (cur_a == )
		}
	}
	a = a;
	return (0);
}
*/

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

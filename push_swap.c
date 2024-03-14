/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:04:09 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/12 18:48:18 by lbaumeis         ###   ########.fr       */
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

int	check_sort(t_list **stack_a)
{
	t_list	*a;
	
	a = *stack_a;
	while (a != 0 && a->next != 0 && a->data < a->next->data)
		a = a->next;
	if ((a->data > a->next->data || a->data == a->next->data) && a->next != 0)
		return (error('i'));
	return (0);
}

t_list	*create_node(t_list **s, int value)
{
	t_list	*n;
	t_list	*stack;
	
	stack = *s;
	n = (t_list *)malloc(sizeof(t_list));
	if (!n)
		return (0);
	n->data = value;
	n->next = NULL;
	n->prev = stack;
	return (n);
}

t_list	**input(char **av, t_list **stack, int ac)
{
	int		x;
	int		y;
	t_list	*s;
	t_list	*node;
	
	x = 1;
	y = 0;
	stack = (t_list **)malloc(sizeof(t_list *) * ac);
	if (!stack)
	{
		ft_printf("Error: malloc\n");
		return (0);
	}
	s = *stack;
	node = NULL;
	if (!av)
		return (0);
	while (av[x][y] && x < ac)
	{
		y = 0;
		while (av[x][y] && ft_isdigit(av[x][y]))
			y++;
		node = create_node(&s, ft_atoi((const char *)av[x]));
		if(!node)
			return (0);
		s = node;
		s = s->next;
		x++;
	}
	node = create_node(&s, 0);
	if(!node)
		return (0);
	s = node;
	s->next = NULL;
	return (stack);
}

int	max(t_list **a)
{
	int		max;
	t_list	*cur;
	
	cur = *a;
	max = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (max < cur->next->data)
			max = cur->next->data;
		cur = cur->next;
	}
	return (max);
}

int	next_min(t_list **a, int repeat, int min)
{
	t_list	*cur;
	int		new_min;

	cur = *a;
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
	
	cur = *a;
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

/*
int	len(t_list **stack)
{
	int		len;
	t_list	*s;
	//t_list	*new;

	len = 0;
	s = *stack;
	//new = NULL;
	while (s != 0 && s->next != 0)
	{
		len++;
		s = s->next;
	}
	//new = (t_list *)malloc(sizeof(t_list) * (len + 1));
	//if (!new)
	//	return (0);
	//new = *stack;
	return (len);
}
*/

t_list	**sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	a = *stack_a;
	b = *stack_b;
	if (a != 0 && b == 0)
	{
		pb(a, b);
		pb(a, b);
		b->next = NULL;
	}
	while (a != 0 && a->next != 0)
	{
		while (b->data > b->next->data)
		{
			sb(b);
			rb(b);
		}
	}
	if (a == 0 && (b->data < b->next->data))
		return (stack_b);
	else
		return (sort(stack_b, stack_a));
}

void	add(t_list *cur, int value)
{
	t_list	*node;

	if (cur == head)
	{
		node->data = value;
		node->next = cur->next;
		cur->next = node;
	}
	else if (cur == NULL)
	{
		node->data = value;
		node->next = (*head);
		
	}
	else if (cur != NULL)
	{
		node->data = value;
		node->next = cur->next;
		cur->next = node;
	}
	
	
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*head;
	int		x;
	
	x = 1;
	a = NULL;
	b = NULL;
	head = NULL;
	if (ac == 1 || ac == 2)
		return (error('i'));
	else if (ac == 0)
		return (0);
	else
	{
		a = (t_list *)malloc(sizeof(t_list *) * ac);
		if (!a)
			return (0);
		while (*av[x] && x <= ac)
		{
			
		}
	}
	stack_b = (t_list **)malloc(sizeof(t_list *) * ac);
	if (!stack_b)
		return (error('m'));
	//a = input(av, a, ac);
	//if (!a)
	//	return (error('w'));
	sort(stack_a, stack_b);
	if (check_sort(stack_a) == 0)
		ft_free(stack_a, stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:26:00 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/22 00:39:44 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_node(t_list *stack, int value)
{
	t_list	*node;

	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->data = value;
	node->next = stack;
	stack->prev = node;
	node->prev = NULL;
	stack = node;
	return (stack);
}

t_list	*stack(t_list *stack, int *input, int elements)
{
	t_list	*s;
	int		x;
	
	if (stack == NULL)
	{
		stack = (t_list *)malloc(sizeof(t_list) * (elements + 1));
		if (!stack)
			return (0);
	}
	s = stack;
	x = 0;
	while (input[x])
		x++;
	while (*input && x >= 0)
	{
		s = add_node(stack, input[x]);
		if (!s)
			return (0);
		x--;
	}
	return (s);
}
/*
char	**one(char **av, char **input)
{
	input = ft_split(av[1], ' ');
	if (!input)
		return (msg(8), NULL);
	if (input[1] == NULL)
		return (msg(2), NULL);
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
		return (NULL);
	while (av[x] && input[y] && x < ac)
		input[y++] = av[x++];
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
	return (input);
}

int	ft_arr_len(char **arr)
{
	int	x;

	x = 0;
	while (arr[x] != NULL)
		x++;
	return (x);
}
*/

/*
void	add_head_node(t_list *head, t_list *node, char id)//insert as first|head
{
	if (id == 'f')
	{
		node->prev = NULL;
		node->next = NULL;
		head = node;
	}
	else if (id == 'h')
	{
		node->prev = NULL;
		node->next = head;
		head->prev = node;
	}
}

void	add_tail_node(t_list *head, t_list *node)//insert as tail
{
	node->next = NULL;
	node->prev = head;
	head->next = node;
}

void	insert_node(t_list *head, t_list *node)//insert after specific node
{
	node->next = head->next;
	node->prev = head;
	head->next = node;
}
*/

/*
void	add_head_node(t_list *head, t_list *node, char id)//insert as first|head
{
	if (id == 'f')
	{
		node->prev = NULL;
		node->next = NULL;
		head = node;
	}
	else if (id == 'h')
	{
		node->prev = NULL;
		node->next = head;
		head->prev = node;
	}
}

void	add_tail_node(t_list *head, t_list *node)//insert as tail
{
	node->next = NULL;
	node->prev = head;
	head->next = node;
}

void	insert_node(t_list *head, t_list *node)//insert after specific node
{
	node->next = head->next;
	node->prev = head;
	head->next = node;
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:26:00 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/18 16:44:15 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **head, int value)
{
	t_list	*node;
	t_list	*temp;

	node = NULL;
	temp = *head;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
	node->next = NULL;
	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
	}
	else
	{
		while (temp->next != 0)
			temp = temp->next;
		node->prev = temp;
		temp->next = node;
	}
	node->next = NULL;
}

t_list	**fill_stack(t_list **stack, char **input)
{
	t_list	**head;
	t_list	*s;
	int		x;
	
	head = stack;
	s = *stack;
	x = 1;
	add_node(head, ft_atoi(input[x]));
	s = s->next;
	x++;
	while (input[x] && s && s->next)
	{
		add_node(stack, ft_atoi(input[x]));
		s = s->next;
		x++;
	}
	add_node(stack, 0);
	return (head);
}

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

t_list	**stack(int	ac, char **av)
{
	t_list	**stack;
	char	**input;
	int		len;

	input = NULL;
	len = 0;
	if (av == NULL)
		len = ac;
	else
	{
		input = get_input(ac, av);
		if (!input)
			return (NULL);
		len = ft_arr_len(input) + 1;
	}
	stack = (t_list **)malloc(sizeof(t_list *) * len);
	if (!stack)
		return (NULL);
	if (av != NULL)
	{
		stack = fill_stack(stack, input);
		if (!stack)
			return (msg(5), ft_free(stack), NULL);
	}
	return (stack);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:26:00 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/14 16:01:03 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head_node(t_list *s, t_list *node, char id)//insert as first|head
{
	if (id == 'f')
	{
		node->prev = NULL;
		node->next = NULL;
		s = node;
	}
	else if (id == 'h')
	{
		node->prev = NULL;
		node->next = s;
		s->prev = node;
	}
}

void	add_tail_node(t_list *s, t_list *node)//insert as tail
{
	node->next = NULL;
	node->prev = s;
	s->next = node;
}

void	insert_node(t_list *s, t_list *node)//insert after specific node
{
	node->next = s->next;
	node->prev = s;
	s->next = node;
}

t_list	*add_node(t_list **stack, int value, char id)
{
	t_list	*s;
	t_list	*node;

	s = *stack;
	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->data = value;
	if (id == 'f' || id == 'h')//insert as first|head
		add_head_node(s, node, id);
	else if (id == 't')//insert as tail
		add_tail_node(s, node);
	else if (id == 'x')//insert after specific node
		insert_node(s, node);
	if (!node)
		return (0);
	return (node);
}

t_list	**fill_stack(t_list **stack, char **input, int len)
{
	t_list	*s;
	int		x;
	
	s = NULL;
	s = *stack;
	if (!s)
		return (0);
	x = 1;
	s = add_node(stack, ft_atoi((const char *)input[x]), 'h');
	if (!s)
		return (0);
	s = s->next;
	x++;
	while (*input[x] && x < len && s && s->next)
	{
		s = add_node(stack, ft_atoi((const char *)input[x]), 'h');
		if (!s)
			return (0);
		s = s->next;
		x++;
	}
	add_node(stack, 0, 't');
	s = *stack;
	if (stack == NULL)
		return (0);
	return (stack);
}

t_list	**stack(int	len)
{
	t_list	**stack;

	stack = NULL;
	stack = (t_list **)malloc(sizeof(t_list *) * len);
	if (!stack)
		return (0);
	return (stack);
}

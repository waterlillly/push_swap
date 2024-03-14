/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:26:00 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/14 15:26:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head_node(t_list **stack, t_list *s, t_list *node, char id)//insert as first|head
{
	s = *stack;
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

void	add_tail_node(t_list **stack, t_list *s, t_list *node)//insert as tail
{
	s = *stack;
	node->next = NULL;
	node->prev = s;
	s->next = node;
}

void	insert_node(t_list **stack, t_list *s, t_list *node)//insert after specific node
{
	s = *stack;
	node->next = s->next;
	node->prev = s;
	s->next = node;
}

void	add_node(t_list **stack, int value, char id)
{
	t_list	*s;
	t_list	*node;

	s = *stack;
	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
	if (id == 'f' || id == 'h')//insert as first|head
		add_head_node(stack, s, node, id);
	else if (id == 't')//insert as tail
		add_tail_node(stack, s, node);
	else if (id == 'x')//insert after specific node
		insert_node(stack, s, node);
}

t_list	**fill_stack(t_list **stack, char **input, int len)
{
	t_list	*s;
	int		x;
	
	s = *stack;
	x = 1;
	add_node(stack, ft_atoi((const char *)input[x]), 'h');
	s = s->next;
	x++;
	while (input[x] && len > 2 && x < len)
	{
		add_node(stack, ft_atoi((const char *)input[x]), 'x');
		s = s->next;
		x++;
	}
	add_node(stack, 0, 't');
	if (*stack == NULL)
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

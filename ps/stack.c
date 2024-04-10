/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:52:22 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/10 01:56:20 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
	node->next = NULL;
	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		node->prev = (*stack);
		(*stack)->next = node;
	}
}

void	push(t_list **src, t_list **dst)
{
	t_list	*new;

	if (!(*src))
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = (*src)->data;
	new->prev = NULL;
	if (!(*dst))
	{
		new->next = NULL;
		(*dst) = new;
	}
	else
	{
		new->next = (*dst);
		(*dst)->prev = new;
		(*dst) = (*dst)->prev;
	}
	if ((*src) && (*src)->next)
	{
		(*src) = (*src)->next;
		(*src)->prev = NULL;
	}
	else
		(*src) = NULL;
}

void	swap(t_list **stack)
{
	int		temp;

	temp = 0;
	if (*stack && (*stack)->next)
	{
		temp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = temp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		last = *stack;
		while (last->next)
			last = last->next;
		temp->next = NULL;
		last->next = temp;
		temp->prev = last;
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		prev_to_last = last->prev;
		prev_to_last->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:52:22 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/08 02:21:49 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, int value)
{
	t_list	*node;
	t_list	*s;

	s = *stack;
	node = malloc(sizeof(t_list *));
	if (!node)
		return ;
	node->data = value;
	node->next = NULL;
	if (!s)
	{
		node->prev = NULL;
		s = node;
	}
	else
	{
		node->prev = s;
		s->next = node;
		s = s->next;
	}
}

void	push(t_list **src, t_list **dst)
{
	t_list	*new;
	t_list	*s;
	t_list	*d;

	s = *src;
	d = *dst;
	if (!s)
		return ;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = s->data;
	new->prev = NULL;
	if (!d)
	{
		new->next = NULL;
		d = new;
	}
	else
	{
		new->next = d;
		d->prev = new;
		d = d->prev;
	}
	if (s && s->next)
	{
		s = s->next;
		s->prev = NULL;
	}
	else
		s = NULL;
}

void	swap(t_list **stack)
{
	int		temp;
	t_list	*s;

	temp = 0;
	s = *stack;
	if (s && s->next)
	{
		temp = s->data;
		s->data = s->next->data;
		s->next->data = temp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;
	t_list	*s;
	
	s = *stack;
	if (s && s->next)
	{
		temp = s;
		s = s->next;
		last = s;
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
	t_list	*s;
	
	s = *stack;
	if (s && s->next)
	{
		last = s;
		while (last->next)
			last = last->next;
		prev_to_last = last->prev;
		prev_to_last->next = NULL;
		last->prev = NULL;
		last->next = s;
		s->prev = last;
		s = last;
	}
}

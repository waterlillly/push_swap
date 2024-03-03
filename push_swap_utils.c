/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:00:30 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/03 06:55:32 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*RETURN INT TO ADD TO CALCULATION ON HOW MANY OPERATIONS NEEDED!*/

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

int	swap(t_list *x)
{
	long int	head;
	long int	next;

	if (x != 0 && x->next != 0)//if only one or no elements: do nothing
	{
		head = x->next->data;
		next = x->data;
		x->data = head;
		x->next->data = next;
		return (1);
	}
	return (0);
}

/*_____SWAP_OPERATIONS_____*/

int	sa(t_list *a)
{
	ft_printf("sa\n");
	return (swap(a));
}

int	sb(t_list *b)
{
	ft_printf("sb\n");
	return (swap(b));
}

int	ss(t_list *a, t_list *b)
{
	ft_printf("ss\n");
	if (swap(a) + swap(b) == 2)
		return (1);
	else
		return (0);
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~PUSH FROM-TO STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

int	push(t_list *dst, t_list *src)
{
	long int	value;
	t_list		*new_head;
	
	value = 0;
	if (src->data != 0)//do nothing if src (=stack to get element from) is empty!
	{
		new_head->prev = NULL;
		new_head->next = dst;
		dst->prev = new_head;
		new_head->data = src->data;
		src->data = src->next->data;
		src = src->next;
		src->prev = NULL;
		return (1);
	}
	return (0);
}

/*_____PUSH_B_TO_A_____*/

int	pa(t_list *a, t_list *b)
{
	ft_printf("pa\n");
	return (push(a, b));
}

/*_____PUSH_A_TO_B_____*/

int	pb(t_list *a, t_list *b)
{
	ft_printf("pb\n");
	return (push(b, a));
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ROTATE STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

/*_____ROTATE_STACK->HEAD_BECOMES_TAIL_____*/

int	rot(t_list *x)
{
	t_list		*new_head;
	t_list		*new_tail;
	
	if (x != 0 && x->next != 0)//if only one or none elements: do nothing-> needed here???
	{
		new_tail->data = x->data;
		new_tail->next = NULL;
		new_head->prev = NULL;	
		new_head->data = x->next->data;
		x = x->next;
		new_head->next = x->next;//?
		while (x != 0 && x->next != NULL)
			x = x->next;
		new_tail->prev = x;
		x->next = new_tail;
		return (1);
	}
	return (0);
}

/*_____REVERSE_ROTATE_STACK->TAIL_BECOMES_HEAD_____*/

int	rev_rot(t_list *x)
{
	t_list		*new_head;
	t_list		*new_tail;
	
	if (x != 0 && x->next != 0)//if only one or none elements: do nothing-> needed here???
	{
		new_head->prev = NULL;
		new_head->next = x;
		x->prev = new_head;
		while (x->next != 0 && x->next->next != NULL)
			x = x->next;
		new_head->data = x->next->data;
		new_tail->data = x->data;
		new_tail->next = NULL;
		new_head->prev = x->prev;
		return (1);
	}
	return (0);
}

/*_____ROTATE_OPERATIONS_____*/

int	ra(t_list *a)
{
	ft_printf("ra\n");
	return (rot(a));
}

int	rb(t_list *b)
{
	ft_printf("rb\n");
	return (rot(b));
}

int	rr(t_list *a, t_list *b)
{
	ft_printf("rr\n");
	if (ra(a) + rb(b) == 2)
		return (1);
	else
		return (0);
}

int	rra(t_list *a)
{
	ft_printf("rra\n");
	return (rev_rot(a));
}

int	rrb(t_list *b)
{
	ft_printf("rrb\n");
	return (rev_rot(b));
}

int	rrr(t_list *a, t_list *b)
{
	ft_printf("rrr\n");
	if (rra(a) + rrb(b) == 2)
		return (1);
	else
		return (0);
}

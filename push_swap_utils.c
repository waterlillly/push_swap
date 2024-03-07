/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:00:30 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/07 15:44:32 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*RETURN INT TO ADD TO CALCULATION ON HOW MANY OPERATIONS NEEDED!*/

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list *x)
{
	long int	head;
	long int	next;

	head = 0;
	next = 0;
	if (x != 0 && x->next != 0)//if only one or no elements: do nothing
	{
		head = x->next->data;
		next = x->data;
		x->data = head;
		x->next->data = next;
	}
}

/*_____SWAP_OPERATIONS_____*/

void	sa(t_list *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_list *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~PUSH FROM-TO STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	push(t_list *dst, t_list *src)
{
	t_list		*new_head;
	
	new_head = NULL;
	if (src->data != 0)//do nothing if src (=stack to get element from) is empty!
	{
		new_head->prev = NULL;
		new_head->next = dst;
		dst->prev = new_head;
		new_head->data = src->data;
		src->data = src->next->data;
		src = src->next;
		src->prev = NULL;
	}
}

/*_____PUSH_B_TO_A_____*/

void	pa(t_list *a, t_list *b)
{
	push(a, b);
	ft_printf("pa\n");
}

/*_____PUSH_A_TO_B_____*/

void	pb(t_list *a, t_list *b)
{
	push(b, a);
	ft_printf("pb\n");
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ROTATE STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

/*_____ROTATE_STACK->HEAD_BECOMES_TAIL_____*/

void	rot(t_list *x)
{
	t_list		*new_head;
	t_list		*new_tail;
	
	new_head = NULL;
	new_tail = NULL;
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
	}
}

/*_____REVERSE_ROTATE_STACK->TAIL_BECOMES_HEAD_____*/

void	rev_rot(t_list *x)
{
	t_list		*new_head;
	t_list		*new_tail;
	
	new_head = NULL;
	new_tail = NULL;
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
	}
}

/*_____ROTATE_OPERATIONS_____*/

void	ra(t_list *a)
{
	rot(a);
	ft_printf("ra\n");
}

void	rb(t_list *b)
{
	rot(b);
	ft_printf("rb\n");
}

void	rr(t_list *a, t_list *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rra(t_list *a)
{
	rev_rot(a);
	ft_printf("rra\n");
}

void	rrb(t_list *b)
{
	rev_rot(b);
	ft_printf("rrb\n");
}

void	rrr(t_list *a, t_list *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

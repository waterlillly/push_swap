/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:00:30 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/22 01:11:06 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*RETURN INT TO ADD TO CALCULATION ON HOW MANY OPERATIONS NEEDED!*/

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list *s)
{
	int		new_head;
	int		old_head;

	new_head = 0;
	old_head = 0;
	if (s != 0 && s->next != 0)//if only one or no elements: do nothing
	{
		new_head = s->next->data;
		old_head = s->data;
		s->data = new_head;
		s->next->data = old_head;
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
	if (src == 0)//do nothing if src is empty!
		ft_printf("error: src_stack is empty");
	else
	{
		dst = add_node(dst, src->data);
		if (!dst)
			return ;
		src->data = src->next->data;
		src = src->next;
		src->prev = src->prev->prev;
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

void	rot(t_list *s)
{
	t_list	*new_head;
	t_list	*new_tail;
	
	new_head = NULL;
	new_tail = NULL;
	if (s != 0 && s->next != 0)//if only one or none elements: do nothing-> needed here???
	{
		new_tail->data = s->data;
		new_tail->next = NULL;
		new_head->prev = NULL;	
		new_head->data = s->next->data;
		s = s->next;
		new_head->next = s->next;//?
		while (s != 0 && s->next != NULL)
			s = s->next;
		new_tail->prev = s;
		s->next = new_tail;
	}
}

/*_____REVERSE_ROTATE_STACK->TAIL_BECOMES_HEAD_____*/

void	rev_rot(t_list *s)
{
	t_list	*new_head;
	t_list	*new_tail;
	
	new_head = NULL;
	new_tail = NULL;
	if (s != 0 && s->next != 0)//if only one or none elements: do nothing-> needed here???
	{
		new_head->prev = NULL;
		new_head->next = s;
		s->prev = new_head;
		while (s->next != 0 && s->next->next != NULL)
			s = s->next;
		new_head->data = s->next->data;
		new_tail->data = s->data;
		new_tail->next = NULL;
		new_head->prev = s->prev;
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
	rot(a);
	rot(b);
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
	rev_rot(a);
	rev_rot(b);
	ft_printf("rrr\n");
}

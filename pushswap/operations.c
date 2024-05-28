/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 18:01:49 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list **stack)
{
	t_list  *one;
	t_list	*two;
	
	one = *stack;
	two = (*stack)->next;
	if (!one || !two)
		return ;
	if (two->next == NULL)
		one->next = NULL;
	else
	    one->next = two->next;
	two->next = one;
	one->prev = two;
	two->prev = NULL;
	*stack = two;
}

/*_____SWAP_OPERATIONS_____*/

void	sa(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~PUSH FROM-TO STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	push(t_list **src, t_list **dst)
{
	t_list	*s;
	int    value;

	s = *src;
	if (!s)
		return ;
	value = s->data;
	add(dst, value);
	if (s->next)
	{
		s = s->next;
		s->prev = NULL;
	}
	else
		s = NULL;
	*src = s;
}

/*_____PUSH_B_TO_A_____*/

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
}

/*_____PUSH_A_TO_B_____*/

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ROTATE STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

/*_____ROTATE_STACK->HEAD_BECOMES_TAIL_____*/

void	rot(t_list **stack)
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
/*_____ROTATE_OPERATIONS_____*/

void	ra(t_list **a)
{
	rot(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	rot(b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rot(a);
	rot(b);
	ft_printf("rr\n");
}

/*_____REVERSE_ROTATE_STACK->TAIL_BECOMES_HEAD_____*/

void	rev_rot(t_list **stack)
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
/*_____REV_ROT_OPERATIONS_____*/

void	rra(t_list **a)
{
	rev_rot(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	rev_rot(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rev_rot(a);
	rev_rot(b);
	ft_printf("rrr\n");
}

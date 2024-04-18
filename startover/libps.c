/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/18 20:16:52 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
    one->next = two->next;
	two->next->prev = one;
	two->next = one;
	one->prev = two;
	two->prev = NULL;
	*stack = two;
}

/*_____SWAP_OPERATIONS_____*/

int	sa(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_list **b)
{
	swap(b);
	ft_printf("sb\n");
	return (1);

}

int	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return (1);
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~PUSH FROM-TO STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	push(t_list **src, t_list **dst)
{
	int		temp;
	t_list	*s;
	t_list	*d;

	temp = 0;
	s = *src;
	d = *dst;
	if (!s)
		return ;
	temp = s->data;
	add(&d, temp);
	if (s->next)
	{
		s = s->next;
		s->prev = NULL;
	}
	else
		s = NULL;
	*src = s;
	*dst = d;
}

/*_____PUSH_B_TO_A_____*/

int	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pa\n");
	return (1);
}

/*_____PUSH_A_TO_B_____*/

int	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pb\n");
	return (1);
}

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ROTATE STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

/*_____ROTATE_STACK->HEAD_BECOMES_TAIL_____*/

void	rot(t_list **stack)
{
    t_list	*new_head;
	t_list	*new_tail;
	t_list	*s;
	
	new_head = NULL;
	new_tail = NULL;
	s = *stack;
	if (!s || !s->next)
		return ;
	new_tail = s;
	new_tail->next = NULL;
	s = s->next;
	new_head = s;
	new_head->prev = NULL;
	new_head->next = s->next;
	while (s->next)
		s = s->next;
	new_tail->prev = s;
	*stack = new_head;
}

/*_____ROTATE_OPERATIONS_____*/

int	ra(t_list **a)
{
	rot(a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_list **b)
{
	rot(b);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_list **a, t_list **b)
{
	rot(a);
	rot(b);
	ft_printf("rr\n");
	return (1);
}

/*_____REVERSE_ROTATE_STACK->TAIL_BECOMES_HEAD_____*/

void	rev_rot(t_list **stack)
{
    t_list	*new_head;
	t_list	*new_tail;
	t_list	*s;

	new_head = NULL;
	new_tail = NULL;
	s = *stack;
	if (!s || !s->next)
		return ;
	while (s->next->next)
		s = s->next;
	new_tail = s;
	new_tail->next = NULL;
	new_tail->prev = s->prev;
	new_head = s->next;
	new_head->prev = NULL;
	while (s)
		s = s->prev;
	new_head->next = s;
	*stack = new_head;
}

/*_____REV_ROT_OPERATIONS_____*/

int	rra(t_list **a)
{
	rev_rot(a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list **b)
{
	rev_rot(b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_list **a, t_list **b)
{
	rev_rot(a);
	rev_rot(b);
	ft_printf("rrr\n");
	return (1);
}

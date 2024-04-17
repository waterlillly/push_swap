/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/17 20:29:46 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list **stack)
{
    int	temp;
	t_list  *s;
	
	temp = 0;
	s = *stack;
	if (!s || !s->next)
		return ;
    temp = s->data;
    s->data = s->next->data;
    s->next->data = temp;
	stack = &s;
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

void	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*s;
	
    if (!src_stack || !*src_stack)
		return ;
    s = *src_stack;
    if (!s->next)
    {
		add_node(dst_stack, s->data);
        s = NULL;
    }
	else
	{
        add_node(dst_stack, s->data);
		s = s->next;
        s->prev = NULL;
    }
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
    if (!stack || !*stack || (*stack)->next == *stack)
		return ;
    *stack = (*stack)->next;
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
    if (!stack || !*stack || (*stack)->next == *stack)
		return ;
    *stack = (*stack)->prev;
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

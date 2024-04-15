/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/15 13:28:17 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list **stack)
{
	t_list  *first;
	t_list	*second;
	t_list  *third;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;        
	second = first->next;  
	third = second->next;


	//The first node becomes the second
	first->prev = second;
	first->next = third;
	//The second node becomes the first and has no previous one
	second->next = first;
	second->prev = NULL;
	//Third's previous node change to first
	third->prev = first;  
	*stack = second;
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
	t_list	*first_src;
	t_list  *first_dst;
	
    if (!src_stack || !*src_stack || !dst_stack || !*dst_stack)
		return ;
    first_src = *src_stack;
	first_dst = *dst_stack;

    // if (first_src->next == NULL)// Only one element in the src stack
    // {
    //     *src_stack = NULL;
    // }
	// else
	// {
    //     *src_stack = first_src->next;
    // }

	*src_stack = first_src->next;

	first_dst->prev = first_src;
	first_src->next = first_dst;

	first_src->prev = NULL;

	*dst_stack = first_src;
}

/*_____PUSH_B_TO_A_____*/

int	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
	return (1);
}

/*_____PUSH_A_TO_B_____*/

int	pb(t_list **a, t_list **b)
{
	push(a, b);
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


	t_list * first = *stack;
	t_list * second = first->next;


	t_list * last = get_last_Node(stack);
	if(!last) 
		return ;

	//Move first element to bottom
	first->next = NULL;
	first->prev = last;
	last->next = first;

	//Make second element the new first
	second->prev =NULL;

    *stack = second;
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
    if (!stack || !*stack)
		return ;


	t_list * first = *stack;

	t_list * last = get_last_Node(stack);
	if(!last || !last->prev)
		return;

	t_list * secondLast = last->prev;

	/* SecondLast Node becomes last */
	secondLast->next = NULL;

	/* Last node becomes first */
	last->prev = NULL;
	last->next = first;

	//First node becomes second
	first->prev = last;

    *stack = last;
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

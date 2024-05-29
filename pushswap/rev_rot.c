/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:50 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 11:15:01 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ROTATE STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:43 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 11:13:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list **stack)
{
	t_list	*one;
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

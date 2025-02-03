/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:43 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	~~~~~~~~~~~~~~~~~~SWAP FIRST TWO INSIDE SAME LIST~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	swap(t_list **stack)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = *stack;
	two = (*stack)->next;
	if (!one || !two)
		return ;
	three = two->next;
	one->next = three;
	two->next = one;
	one->prev = two;
	two->prev = NULL;
	if (three)
		three->prev = one;
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

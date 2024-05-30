/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 14:36:21 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~~~~~~~PUSH FROM-TO STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	push(t_list **src, t_list **dst)
{
	t_list	*s;
	int		value;

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

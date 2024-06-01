/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:08 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/30 10:02:56 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	~~~~~~~~~~~~~~~~~~~~~~~~PUSH FROM-TO STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~	*/
/*	**********************************************************************	*/

void	push(t_list **src, t_list **dst)
{
	t_list	*s;
	t_list	*tmp;
	int		value;

	s = *src;
	if (!s)
		return ;
	value = s->data;
	if (add(dst, value))
		error(src, dst);
	if (s->next)
	{
		tmp = s;
		s = s->next;
		free(tmp);
		s->prev = NULL;
	}
	else
	{
		free(s);
		s = NULL;
	}
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

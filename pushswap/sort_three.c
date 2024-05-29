/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:16:13 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 12:21:42 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (!s || !s->next || !s->next->next)
		error();
	if (s->data < s->next->data)
		sort_three_a(&s);
	else
		sort_three_b(&s);
	*stack = s;
}

void	sort_three_a(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (s->next->data < s->next->next->data)
		return ;
	else
	{
		if (s->data < s->next->next->data)
		{
			rra(&s);
			sa(&s);
		}
		else
			rra(&s);
	}
	*stack = s;
}

void	sort_three_b(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (s->next->data < s->next->next->data)
	{
		if (s->data < s->next->next->data)
			sa(&s);
		else
			ra(&s);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			sa(&s);
			rra(&s);
		}
	}
	*stack = s;
}

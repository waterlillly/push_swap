/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:11:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/30 11:31:34 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_seq(t_list *start, t_list *end, int mark)
{
	t_list	*p;

	p = start;
	while (p)
	{
		p->seq = mark;
		if (p == end)
		{
			p->seq = 2;
			break ;
		}
		p = p->next;
	}
}

void	update_max_seq(int cur_l, int *max_l, t_list *start, t_list *p, t_list **s, t_list **e)
{
	if (cur_l > *max_l)
	{
		if (*s)
			mark_seq(*s, *e, 0);
		*s = start;
		*e = p;
		*max_l = cur_l;
	}
}

int	check_seq(t_list **stack_a, int cur_l)
{
	t_list	*p;

	p = *stack_a;
	if ((*stack_a)->next && (*stack_a)->next->data > p->data)
		cur_l++;
	return (cur_l);
}

void	reset_seq(t_list **s_a, int *cur_l, int *max_l, t_list **s, t_list **e)
{
	t_list	*p;
	t_list	*start;

	p = *s_a;
	start = *s_a;
	update_max_seq(*cur_l, max_l, start, p, s, e);
	*cur_l = 1;
	*s_a = (*s_a)->next;
}

void	longest_sorted_seq(t_list *a)
{
	int		max_l;
	int		cur_l;
	t_list	*s;
	t_list	*e;

	max_l = 0;
	cur_l = 1;
	s = NULL;
	e = NULL;
	while (a)
	{
		cur_l = check_seq(&a, cur_l);
		if (cur_l == 1)
			reset_seq(&a, &cur_l, &max_l, &s, &e);
	}
	if (s)
		mark_seq(s, e, 1);
}

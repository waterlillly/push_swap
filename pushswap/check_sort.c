/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:04:30 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/31 17:54:37 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_check(int ac, char **input, t_list **head)
{
	if (ac == 2)
		ft_free(input);
	error(head, NULL);
}

void	error(t_list **a, t_list **b)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_list *stack)
{
	t_list	*s;

	s = stack;
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/31 17:42:15 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = a;
	ft_printf("\nA:\n");
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
	tmp = b;
	ft_printf("B:\n");
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	fill_stack(ac, av, &a);
	if (!is_sorted(a))
		sort(&a, &b);
	show(a, b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}

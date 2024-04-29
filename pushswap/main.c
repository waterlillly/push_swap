/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/29 21:21:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	else if (ac == 2 && !(valid_arg(av)))
		return (0);
	else
		fill_stack(ac, av, &a);
	sort(&a, &b);
	if (!is_sorted(a))
		ft_printf("\nKO\n");
	else
		ft_printf("\nOK\n");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}

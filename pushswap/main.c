/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/28 15:18:21 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		x;
	int		y;

	a = NULL;
	b = NULL;
	x = 0;
	y = 0;
	if (ac <= 1 || (ac == 2 && !(valid_arg(av))))
		return (0);
	fill_stack(ac, av, &a);
	if (!is_sorted(a))
	{
		y = how_to_sort(&a, &b);
		if (y == -1)
			return (0);
		x += y;
	}
	if (!is_sorted(a))
		ft_printf("\nERROR\n");
	ft_printf("\nSTACK A:\n");
	show(a);
	ft_printf("\n%d moves\n", x);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}

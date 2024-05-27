/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/27 12:14:03 by lbaumeis         ###   ########.fr       */
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
	if (!is_sorted(a) && stack_size(a) <= 5)
		x += sort_five_max(&a, &b);
	else if (!is_sorted(a))
	{
		x += rot_until(&a, find_max(a));
		x += pb(&a, &b);
		x += pb(&a, &b);
	}
	while (!is_sorted(a) && stack_size(a) > 3)
	{
		update(&a, &b);
		y = rot_cheapest(&a, &b);
		if (y == -1)
			return (-1);
		else
			x += y;
		x += pb(&a, &b);
	}
	if (!is_sorted(a))
		x += sort_three(&a);
	while (b)
	{
		final(&a, &b);
		y = rot_cheapest(&a, &b);
		if (y == -1)
			return (-1);
		else
			x += y;
		x += pa(&a, &b);
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

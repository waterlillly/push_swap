/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/16 22:33:54 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		x;

	a = NULL;
	b = NULL;
	x = 0;
	if (ac <= 1 || (ac == 2 && !(valid_arg(av))))
		return (0);
	fill_stack(ac, av, &a);
	if (!is_sorted(a) && stack_size(a) <= 5)
		x += sort_five_max(&a, &b);
	else
	{
		while (!is_sorted(a) && stack_size(a) > 3)
		{
			update(&a, &b);
			x += rot_cheapest(&a, &b);
			x += pb(&a, &b);
		}
		if (!is_sorted(a))
			x += sort_three(&a);
		while (b)
		{
			final(&a, &b);
			x += rot_cheapest(&a, &b);
			x += pa(&a, &b);
		}
	}
	if (!is_sorted(a))
		ft_printf("ERROR\n");
	show(a);
	ft_printf("%d moves\n", x);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		x;

	a = NULL;
	b = NULL;
	x = 0;
	if (ac <= 1)
		return (0);
	else if (ac == 2 && !(valid_arg(av)))
		return (0);
	else
		fill_stack(ac, av, &a);
	x += sort_more(&a, &b);
	ft_printf("%d steps\n", x);
	if (!is_sorted(a))
		ft_printf("\nKO\n");
	else
		ft_printf("\nOK\n");
	show(a);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
*/
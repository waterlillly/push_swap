/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/14 15:26:20 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	
	a = NULL;
	b = NULL;
	if (is_sorted(ac, av) == 1)
		return (0);
	if (check_input(ac, av) == 1)
	{
		a = stack(ac);
		if (!a)
			return (0);
		a = fill_stack(a, av, ac);
		if (!a)
			ft_free(a, b);
		b = stack(ac);
		if (!b)
			return (ft_free(a, b), 0);
		if (check_sort(a) != 1)
			a = dd_sort(a, b);
		else if (check_sort(a) == 1)
		{
			ft_printf("is sorted");
			ft_free(a, b);
			return (0);
		}
		else
		{
			ft_printf("not sorted");
			return (0);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/15 15:56:58 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	
	if (ac <= 2 || av[1] == NULL)
		return (msg(1), 0);
	if (is_sorted(ac, av) == 1)
	{
		a = NULL;
		a = stack(ac, av);
		if (!a)
			return (msg(5), ft_free(a), 0);
		if (ac > 4)
		{
			b = NULL;
			b = stack(ac, NULL);
			if (!b)
				return (ft_free(a), 0);
			dd_sort(a, b);
		}
		if (check_sort(a) == 1 && !b)
			return (msg(6), ft_free(a), ft_free(b), 0);
		else
			return (msg(7), ft_free(a), ft_free(b), 0);
	}
	return (msg(1), 0);
}

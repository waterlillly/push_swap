/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/14 13:54:33 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	
	if (first_check(ac, av) == 1)
		return (0);
	if (check_input(ac, av) == 1)
	{
		a = stack(ac);
		if (!a)
			return (0);
		fill(a, av, ac);
		b = stack(ac);
		if (check_doubles(ac, 1, a) != 1)
			error(2);
		else if (check_sort(a) == 1)
			error(33);
		else
			dd_sort(a, b);
		if (check_sort(a) == 1)
		{
			ft_free(a, b);
			return (0);
		}
		else
			return (error(3), 0);
	}
	return (error(1), 0);
}

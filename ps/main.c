/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:06:48 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/10 01:58:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_a = fill_stack_a(ac, av);
	ft_printf("%d elements in stack\n", stack_size(stack_a));
	print_stack(stack_a);
	sort_numbers(stack_a, stack_b);
	return (ft_printf("done\n"), 1);
}

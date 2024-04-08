/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:06:48 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/08 03:11:33 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = malloc(sizeof(t_list *));
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		return (0);
	a = &stack_a;
	if (ac < 2)
		return (0);
	a = fill_stack_a(ac, av);
	print_stack(a);
	sort_numbers(a, &stack_b);
	return (ft_printf("done\n"), 1);
}

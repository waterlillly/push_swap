/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/04 20:09:57 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
	int		counter;
	
	counter = 0;
	stack_a = NULL;
	stack_a = parse_arguments(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	counter += sort(&stack_a, &stack_b, counter);
	if (is_sorted(stack_a) && counter <= 700)
		ft_printf("done with: %d steps\n", counter);
	else
		ft_printf("took more than 700 steps: %d\n", counter);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
    return (0);
}
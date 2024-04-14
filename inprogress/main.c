/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/14 23:33:14 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find(char *str, int c)
{
	int	i;
	int	occ;

	i = 0;
	occ = 0;
	while (str[i])
	{
		if (str[i] == c)
			occ++;
		i++;
	}
	if (c == '\0')
		return (1);
	else if (occ == 0)
		return (-1);
	return (occ);
}

int	valid_arg(char **av)
{
	int		x;
	char	*in;

	x = 0;
	in = av[1];
	if (ft_find(in, ' ') == -1)
	{
		if (ft_atoi(in) >= INT_MIN && ft_atoi(in) <= INT_MAX)
			return (ft_printf("only one number\n"), 0);
		else
			return (ft_printf("not valid\n"), 0);
	}
	if (in[0] == '-')
		x++;
	else if (in[0] == ' ')
		return (0);
	while (in[x])
	{
		if (in[x] == '-' && ft_isdigit(in[x + 1]))
			x++;
		while (in[x] && ft_isdigit(in[x]))
			x++;
		if (in[x] == ' ' && (in[x + 1] == '-' || ft_isdigit(in[x + 1])))
			x++;
	}
	return (1);
}

int main(int ac, char **av)
{
    t_list **stack_a;
	t_list  *a;
    t_list **stack_b;
	int		counter;
	
	if (ac <= 1 || (ac == 2 && !valid_arg(av)))
		return (0);	
	counter = 0;
	stack_a = NULL;
	a = malloc(sizeof(t_list));
	if (!a)
		return (0);
	stack_a = &a;
	stack_b = NULL;
	parse_arguments(ac, av, stack_a);
	stack_a = &a;
	if (!stack_a)
		return (0);
	counter += sort(stack_a, stack_b, counter);
	if (is_sorted(stack_a))
		ft_printf("done with: %d steps\n", counter);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/22 01:34:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*arr;
	int		elements;
	t_list	*a;
	t_list	*b;
	
	arr = NULL;
	elements = 0;
	a = NULL;
	b = NULL;
	arr = check_input(ac, av);
	if (!arr)
		return (0);
	elements = arr_len(arr);
	a = stack(a, arr, elements);
	free(arr);
	if (!a)
		return (ft_free(a), 0);
	//if (elements == 3)	
	//	sort_three(a);
	if (elements > 1)
	{
		b = (t_list *)malloc(sizeof(t_list) * (elements + 1));
		if (!b)
			return (ft_free(a), 0);
		dd_sort(a, b);
	}
	if (check_sort(a) == 1 && !b)
		return (ft_free(a), ft_free(b), 0);
	else
		return (ft_free(a), ft_free(b), 0);
	return (0);
}

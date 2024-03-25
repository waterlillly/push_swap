/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/25 21:15:17 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		**arr;
	int		elements;
	t_list	*a;
	
	arr = NULL;
	elements = 0;
	a = NULL;
	arr = check_input(ac, av);
	if (!arr)
		return (0);
	elements = arr_len(arr);
	a = stack(a, arr, elements);
	free(arr);
	if (!a)
		return (ft_free(a), 0);
	if (elements < 2)
		return (0);
	else if (elements == 2)
	{
		if (a->data < a->next->data)
			return (ft_printf("sorted!"), ft_free(a), 0);
		else
			sa(a);
	}	
	else if (elements >= 3)
		a = sort(a, elements);
	if (check_sort(a))	
		return (ft_free(a), 0);
	else
		return (ft_printf("sorry, not possible to sort"), 0);	
}

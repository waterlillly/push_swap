/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/27 11:24:09 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**arr;
	int		elements;
	t_list	*a;
	
	a = NULL;
	arr = check_input(ac, av);
	if (!arr)
		return (0);
	elements = arr_len(arr);
	if (elements < 2)
		return (free(arr), 0);
	a = stack(a, arr, elements);
	free(arr);
	if (!a)
		return (ft_free(a), 0);
	else if (elements == 2)
	{
		if (a && a->next && (a->data < a->next->data))
			return (ft_printf("sorted!"), ft_free(a), 0);
		else
			sa(a);
	}	
	else if (elements >= 3)
		sort(a, elements);
	if (check_sort(a))	
		return (ft_free(a), 0);
	else
		return (ft_printf("sorry, not possible to sort"), 0);	
}

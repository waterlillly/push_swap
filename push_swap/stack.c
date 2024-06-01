/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/31 17:51:25 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	add(t_list **head, int value)
{
	t_list	*node;

	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->data = value;
	node->index = 0;
	node->price = 0;
	node->cheapest = 0;
	node->seq = 0;
	node->target = NULL;
	node->prev = NULL;
	if (*head)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	else
		node->next = NULL;
	*head = node;
	return (0);
}

bool	fill_stack_2(char **input, int x, int y, t_list **head)
{
	while (y >= x && input[y])
	{
		if (add(head, ft_atoi(input[y])))
			return (1);
		y--;
	}
	return (0);
}

bool	fill_stack(int ac, char **av, t_list **head)
{
	char	**input;
	int		x;
	int		y;

	input = NULL;
	x = 0;
	if (ac > 2)
	{
		x = 1;
		input = av;
	}
	else if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		if (!input)
			error(head, NULL);
	}
	if (!check_doubles(input, x) || ft_check_arg(x, input) == false)
		err_check(ac, input, head);
	y = arr_len(input) - 1;
	if (fill_stack_2(input, x, y, head))
		err_check(ac, input, head);
	if (ac == 2)
		ft_free(input);
	return (0);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	s = NULL;
}

void	ft_free_stack(t_list **stack)
{
	t_list	*s;
	t_list	*tmp;

	s = *stack;
	tmp = NULL;
	while (s)
	{
		tmp = s->next;
		free(s);
		s = NULL;
		s = tmp;
	}
	s = NULL;
	tmp = NULL;
}

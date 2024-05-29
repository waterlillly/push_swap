/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/29 12:51:56 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add(t_list **head, int value)
{
	t_list	*node;

	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		ft_free_stack(head);
		return ;
	}
	node->data = value;
	node->index = 0;
	node->price = 0;
	node->cheapest = 0;
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
}

void	fill_stack(int ac, char **av, t_list **head)
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
			return ;
	}
	if (!check_doubles(input, x))
		return ;
	y = arr_len(input) - 1;
	while (input[y] && y >= x)
	{
		add(head, ft_atoi(input[y]));
		y--;
	}
	ft_free(input);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] && i >= 0)
	{
		free(s[i]);
		i--;
	}
	s = NULL;
	free(s);
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
	free(s);
	free(tmp);
	s = NULL;
	tmp = NULL;
}

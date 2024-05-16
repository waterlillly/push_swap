/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/16 22:50:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add(t_list **head, int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
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
	{
		ft_printf("error: doubles in input\n");
		return ;
	}
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
		s = NULL;
		free(s);
		s = tmp;
	}
	s = NULL;
	free(s);
	free(tmp);
	stack = NULL;
}

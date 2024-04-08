/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:00:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/08 03:06:44 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**fill_stack_a(int ac, char **av)
{
	t_list	*a;
	t_list	**stack_a;
	char	**tokens;
	int		i;
	
	a = malloc(sizeof(t_list *));
	if (!a)
		return (NULL);
	stack_a = &a;
	tokens = NULL;
	i = 0;
	if (ac == 2 && is_valid(av[1]))
	{
		tokens = ft_split(av[1], ' ');
		if (!tokens)
			return (NULL);
		while (tokens[i])
		{
			add_node(stack_a, ft_atoi(tokens[i]));
			i++;
		}
	}
	else
		parse_and_fill(stack_a, ac, av);
	stack_a = &a;
	return (stack_a);
}

void	print_stack(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (!s)
	{
		ft_printf("error\n");
		return ;
	}
	while (s && s->next)
	{
		ft_printf("%d\n", s->data);
		s = s->next;
	}
}

void	parse_and_fill(t_list **stack_a, int ac, char **av)
{
	int		i;
	int		value;
	t_list	*a;

	i = 1;
	value = 0;
	a = *stack_a;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		add_node(&a, value);
		i++;
	}
}

int	is_valid(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*str++)))
			str++;
		else if (*str == ' ' && (*str++ == '-' || ft_isdigit(*str++)))
			str++;
		else
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:00:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/10 01:33:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**fill_stack_a(int ac, char **av)
{
	t_list	**stack_a;
	char	**tokens;
	int		i;
	
	stack_a = malloc(sizeof(t_list *));
	if (!stack_a)
		return (NULL);
	*stack_a = NULL;
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
	return (stack_a);
}

void	print_stack(t_list **stack)
{
	if (!(*stack))
	{
		ft_printf("error\n");
		return ;
	}
	while ((*stack))
	{
		ft_printf("%d\n", (*stack)->data);
		(*stack) = (*stack)->next;
	}
}

void	parse_and_fill(t_list **stack_a, int ac, char **av)
{
	int		i;
	t_list	*a;

	i = 1;
	a = *stack_a;
	while (i < ac)
	{
		add_node(stack_a, ft_atoi(av[i]));
		i++;
	}
	stack_a = &a;
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

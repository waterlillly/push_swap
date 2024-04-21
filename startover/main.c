/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:40 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/21 16:44:58 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	show(t_list *stack)
{
	t_list	*s;

	s = stack;
	while (s)
	{
		ft_printf("%d\n", s->data);
		s = s->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		x;

	a = NULL;
	b = NULL;
	x = 0;
	if (ac <= 1)
		return (0);
	else if (ac == 2 && !(valid_arg(av)))
		return (0);
	else
		fill_stack(ac, av, &a);
	while (!is_sorted(&a))
		x += sort(&a, &b);
	ft_printf("%d steps\n", x);
	ft_printf("a:\n");
	show(a);
	ft_printf("b:\n");
	show(b);
	return (0);
}

/*
void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] && i >= 0)
		free(s[i--]);
	s = NULL;
	free(s);
}

void	ft_free_list(t_list **stack)
{
	t_list  *s;

	if (!stack)
		return ;
	s = *stack;
	if (s->next != 0)
		s = s->next;
	while (s != NULL && s->next != NULL)
	{
		free(s->prev);
		s = s->next;
	}
	s = NULL;
	free(s);
}

int	check_doubles(int ac, char **av)
{
	int	x;
	int	y;
	int	z;

	x = 1;
	y = 0;
	z = 2;
	while (**av && x < ac)
	{
		y = ft_atoi(av[x]);
		while (**av && z < ac)
		{
			if (y == ft_atoi(av[z]))
				return (0);
			z++;
		}
		x++;
		z = x + 1;
	}
	return (1);
}

int	check_int_doubles(t_list **a)
{
	int			x;
	int			y;
	int 	*nbr;

	x = 0;
	y = 0;
	nbr = (int *)&a;
	while (in[x] && ft_isdigit(in[x])
	{
		if (x > 0)
		{
			y = x - 1;
			while (in[x] && y >= 0)
			{
				if (ft_strncmp(in[y], in[x], ft_strlen(in[x]) == 0)
					return (error('d'));
				else
					y--;
			}
		}
		x++;
	}
	return (0);
}
*/
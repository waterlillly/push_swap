
#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*s;

	s = *stack;
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	*stack = s;
	return (1);
}

int	arr_len(char **input)
{
	int	x;

	x = 0;
	if (!input)
		return (0);
	while (input[x])
		x++;
	return (x);
}

int	check_doubles(char **input, int x)
{
	int	y;
	int	z;

	y = 0;
	z = x + 1;
	while (input[x])
	{
		y = ft_atoi(input[x]);
		while (input[z])
		{
			if (y == ft_atoi(input[z]))
				return (0);
			z++;
		}
		x++;
		z = x + 1;
	}
	return (1);
}

int	stack_size(t_list *stack)
{
	int		x;
	t_list  *s;

	s = stack;
	if (!s)
		return (-1);
	x = 0;
	while (s)
	{
		x++;
		s = s->next;
	}
	return (x);
}

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
	return (occ);
}

int	valid_arg(char **av)
{
	int		x;
	char	*in;
	char    c;

	x = 0;
	in = av[1];
	c = in[ft_strlen(in)];
	if (ft_find(in, ' ') == 0 && (ft_isdigit(c)
					&& (ft_atoi(in) >= INT_MIN && ft_atoi(in) <= INT_MAX)))
		return (0);
	else if (c == ' ' || c == '-')
		return (ft_printf("invalid\n"), 0);
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
		if (in[x] == ' ' && (in[x + 1] == '-' && ft_isdigit(in[x + 1])))
			x++;
		else if (in[x] == ' ' && ft_isdigit(in[x + 1]))
			x++;
		else if (in[x] == ' ' && (in[x + 1] == '-' || in[x + 1] == ' ')
					 && in[x + 2] == '\0')
			return (ft_printf("error: invalid input\n"), 0);
		else
			return (ft_printf("error\n"), 0);
	}
	return (1);
}

int	find_min(t_list *stack)
{
	int	min;
	t_list  *s;

	min = INT_MAX;
	s = stack;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;
	t_list  *s;

	max = INT_MIN;
	s = stack;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

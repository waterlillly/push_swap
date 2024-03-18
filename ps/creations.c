/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:25:05 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/18 18:09:48 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_node(t_list *head, int value)
{
	t_list	*node;
	t_list	*temp;

	node = NULL;
	temp = head;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->data = value;
	node->next = NULL;
	if (head == NULL)
	{
		node->prev = NULL;
		head = node;
	}
	else
	{
		while (temp->next != 0)
			temp = temp->next;
		node->prev = temp;
		temp->next = node;
	}
	return (node);
}

t_list	*fill_stack(t_list *stack, char **input)
{
	t_list	*head;
	t_list	*s;
	int		x;
	
	head = stack;
	head->prev = NULL;
	head->next = NULL;
	s = head->next;
	s->prev = head;
	x = 0;
	if (!stack)
	{
		head = add_node(stack, ft_atoi(input[x]));
		x++;
	}
	while (input[x] && s && s->next)
	{
		s = add_node(stack, ft_atoi(input[x]));
		s = s->next;
		x++;
	}
	s = head;
	return (head);
}

char	**one(char **av, char **input)
{
	input = ft_split(av[1], ' ');
	if (!input)
		return (msg(8), NULL);
	if (input[1] == NULL)
		return (msg(2), NULL);
	else
		return (input);
}

char	**two(int ac, char **av, char **input)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	input = (char **)malloc(sizeof(char *) * ac);
	if (!input)
		return (NULL);
	while (av[x] && input[y] && x < ac)
		input[y++] = av[x++];
	input[y] = NULL;
	return (input);
}

char	**get_input(int ac, char **av)
{
	char	**input;

	input = NULL;
	if (ac == 2)
	{
		input = one(av, input);
		if (!input)
			return (0);
	}
	else
	{
		input = two(ac, av, input);
		if (!input)
			return (0);
	}
	return (input);
}

int	ft_arr_len(char **arr)
{
	int	x;

	x = 0;
	while (arr[x] != NULL)
		x++;
	return (x);
}

t_list	*stack(int	ac, char **av)
{
	t_list	*stack;
	char	**input;
	int		len;

	stack = NULL;
	input = NULL;
	len = 0;
	input = get_input(ac, av);
	if (!input)
		return (NULL);
	if (ac == 2)
		len = ft_arr_len(input) + 1;
	else
		len = ac;
	stack = (t_list *)malloc(sizeof(t_list) * len);
	if (!stack)
		return (NULL);
	stack = fill_stack(stack, input);
	if (!stack)
		return (msg(5), ft_free(stack), NULL);
	return (stack);
}

/*
int	ft_countstrs(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

int	ft_place(char const *s, char c, int last_pos)
{
	while (s[last_pos] != '\0' && s[last_pos] != c)
		last_pos++;
	return (last_pos);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		x;
	int		last_pos;

	last_pos = 0;
	result = malloc((ft_countstrs(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	x = 0;
	while (x < ft_countstrs(s, c))
	{
		while (s[last_pos] == c)
			last_pos++;
		result[x] = ft_substr(s, last_pos, ft_place(s, c, last_pos) - last_pos);
		if (!result[x++])
		{
			while (x > 0)
				free(result[--x]);
			free(result);
			return (NULL);
		}
		last_pos = ft_place(s, c, last_pos + 1);
	}
	result[x] = NULL;
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*src;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	src = (char *)s;
	size = ft_strlen(s) - start;
	if (len > size)
		len = size;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (src[i] && i < len)
	{
		sub[i] = src[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *c)
{
	size_t	b;
	char	*duplo;

	b = ft_strlen(c) + 1;
	duplo = (char *)malloc((sizeof(char) * b));
	if (!duplo)
		return (NULL);
	ft_strlcpy(duplo, c, b);
	return (duplo);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	s;

	srclen = ft_strlen(src);
	s = 0;
	if (size == 0)
		return (srclen);
	while (src[s] != '\0' && s < size - 1)
	{
		dst[s] = src[s];
		s++;
	}
	dst[s] = '\0';
	return (srclen);
}

int ft_strlen(const char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/20 08:37:38 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *base, char *add)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	i = 0;
	j = 0;
	len = ft_strlen(base) + ft_strlen(add);
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	while (base[i])
	{
		join[i] = base[i];
		i++;
	}
	while (add[j])
	{
		join[i + j] = add[j];
		j++;
	}
	join[i + j] = '\0';
	return (free(base), join);
}

char	*ft_dup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = NULL;
	if (!str)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

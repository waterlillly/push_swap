/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/20 08:38:21 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buf(char *buf, int *x)
{
	char	*line;
	int		j;

	line = NULL;
	j = 0;
	while (buf[*x] && buf[*x] != '\n')
		(*x)++;
	if (buf[*x] == '\n')
		(*x)++;
	if (*x == 0)
		return (NULL);
	line = malloc(sizeof(char) * (*x + 1));
	if (!line)
		return (NULL);
	line[*x] = '\0';
	while (j < *x)
	{
		line[j] = buf[j];
		j++;
	}
	return (line);
}

char	*ft_rest(int x, char *buf)
{
	char	*temp;
	int		y;

	temp = NULL;
	y = 0;
	while (buf[x + y])
		y++;
	temp = malloc(sizeof(char) * (y + 1));
	if (!temp)
		return (NULL);
	temp[y] = '\0';
	y = 0;
	while (buf[x + y])
	{
		temp[y] = buf[x + y];
		y++;
	}
	free(buf);
	return (temp);
}

char	*ft_next(char *buf, int fd)
{
	int		bytes;
	char	*temp;

	bytes = 0;
	temp = NULL;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (free(buf), buf = NULL, NULL);
	while (ft_strchr(buf, '\n') == 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), buf = NULL, free(temp), NULL);
		else if (bytes == 0)
			break ;
		temp[bytes] = '\0';
		if (!temp)
			return (NULL);
		buf = ft_strjoin(buf, temp);
		if (!buf)
			return (NULL);
	}
	return (free(temp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;	
	char		*next;
	int			x;

	next = NULL;
	x = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = ft_dup("");
		if (!buf)
			return (NULL);
	}
	buf = ft_next(buf, fd);
	if (!buf)
		return (NULL);
	next = ft_buf(buf, &x);
	if (!next)
		return (free(buf), buf = NULL, NULL);
	buf = ft_rest(x, buf);
	if (!buf)
		return (free(next), NULL);
	return (next);
}

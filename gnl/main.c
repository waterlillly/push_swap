/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:50:52 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/20 06:01:56 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;
	time_t	start;
	time_t	end;

	time (&start);
	i = 1;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("--->LINE %d: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
		if (line == NULL)
		{
			printf("LINE %d: %s", i, line);
			break ;
		}
	}
	printf("[[]]\n\nBUFFER_SIZE: %d[]\nFD: %d[]\n", BUFFER_SIZE, fd);
	time (&end);
	return (free(line), printf ("time: %.3lf seconds[[]]\n\n", difftime (end, start)), 0);
}

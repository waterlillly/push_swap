/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:50 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/20 08:38:40 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char *base, char *add);
int		ft_strchr(char *s, int c);
char	*ft_buf(char *buf, int *x);
char	*ft_next(char *buf, int fd);
char	*ft_dup(char *str);
char	*ft_rest(int x, char *buf);

#endif

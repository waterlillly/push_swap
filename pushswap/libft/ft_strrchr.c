/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:41:03 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/09/25 16:41:03 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	find;

	i = (int)ft_strlen(s);
	str = (char *)s;
	find = (char)c;
	while (i >= 0)
	{
		if (c == '\0')
			return (&str[i]);
		else if (str[i] == find)
			return (&str[i]);
		else
			i--;
	}
	return (NULL);
}

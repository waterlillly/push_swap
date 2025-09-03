/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:57:31 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/09/03 20:52:03 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	char			*z;
	char			*str;

	x = 0;
	str = (char *)s;
	z = (char *)malloc(sizeof(char) * ((ft_strlen(s) + 1)));
	if (!z)
		return (NULL);
	while (str[x] != '\0')
	{
		z[x] = f(x, str[x]);
		x++;
	}
	z[x] = '\0';
	return (z);
}

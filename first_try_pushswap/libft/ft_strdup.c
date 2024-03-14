/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:01 by lbaumeis          #+#    #+#             */
/*   Updated: 2023/10/08 10:56:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *d)
{
	size_t	b;
	char	*duplo;

	b = ft_strlen(d) + 1;
	duplo = (char *)malloc((sizeof(char) * b));
	if (!duplo)
		return (NULL);
	ft_strlcpy(duplo, d, b);
	return (duplo);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:36:59 by jwozniak          #+#    #+#             */
/*   Updated: 2018/01/24 15:16:44 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	if ((dest = ((char *)malloc(ft_strlen(src) + 1))))
	{
		i = -1;
		while (src[++i])
			dest[i] = src[i];
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}

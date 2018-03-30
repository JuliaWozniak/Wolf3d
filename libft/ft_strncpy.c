/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:48:00 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:48:19 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
	{
		while (i < num)
			dest[i++] = '\0';
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:34:13 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:35:18 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char*)dest;
	s = (const char*)src;
	if (d < s)
	{
		while (num > 0)
		{
			*d++ = *s++;
			num--;
		}
	}
	else
	{
		while (num--)
			*(d + num) = *(s + num);
	}
	return (dest);
}

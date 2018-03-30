/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:25:14 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:26:22 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dl;
	size_t		sz;

	s = src;
	d = dst;
	sz = size;
	while (sz-- && *d)
		d++;
	dl = d - dst;
	sz = size - dl;
	if (sz == 0)
		return (dl + ft_strlen(s));
	while (*s)
	{
		if (sz != 1)
		{
			*d++ = *s;
			sz--;
		}
		s++;
	}
	*d = '\0';
	return (dl + (s - src));
}

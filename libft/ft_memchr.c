/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:30:22 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:36:38 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	cu;

	p = (unsigned char*)s;
	cu = (unsigned char)c;
	while (n--)
	{
		if (*p != cu)
			p++;
		else
			return (p);
	}
	return (NULL);
}

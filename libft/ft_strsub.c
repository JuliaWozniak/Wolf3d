/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:10:16 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:11:06 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *p;

	if (s == NULL)
		return (NULL);
	p = (char *)malloc(len + 1);
	if (p)
	{
		p = ft_strncpy(p, (s + start), len);
		p[len] = '\0';
	}
	return (p);
}

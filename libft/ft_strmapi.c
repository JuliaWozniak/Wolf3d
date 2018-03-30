/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:35:47 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:31:24 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	n;
	unsigned int	i;

	i = -1;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	n = ft_strlen(s);
	p = (char *)malloc(n + 1);
	if (p)
	{
		p[n] = '\0';
		while (++i < n)
			p[i] = (*f)(i, s[i]);
	}
	return (p);
}

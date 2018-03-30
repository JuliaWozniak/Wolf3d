/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:35:24 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:26:47 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		n;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	n = ft_strlen(s);
	p = (char *)malloc(n + 1);
	if (p)
	{
		p[n] = '\0';
		while (n--)
			p[n] = (*f)(s[n]);
	}
	return (p);
}

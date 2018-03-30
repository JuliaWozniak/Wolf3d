/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:08:27 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:29:59 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*ns;
	int		n;

	if (s == NULL)
		return (NULL);
	start = (char *)s;
	end = ft_strchr(s, '\0');
	end--;
	while (ft_isspace(*start))
		start++;
	while (ft_isspace(*end) && end > start)
		end--;
	n = end - start + 1;
	ns = (char *)malloc(n + 1);
	if (ns)
	{
		ns = ft_strncpy(ns, start, n);
		ns[n] = '\0';
	}
	return (ns);
}

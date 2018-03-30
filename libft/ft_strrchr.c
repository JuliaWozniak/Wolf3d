/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:33:59 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:31:05 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char*)&str[i]);
	while (--i >= 0)
	{
		if (str[i] == c)
			return ((char*)&str[i]);
	}
	return (NULL);
}

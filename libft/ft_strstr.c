/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:39:26 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:38:43 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	size_t	len;
	int		res;

	i = 0;
	len = ft_strlen(to_find);
	if (to_find[0] == '\0')
	{
		return ((char *)&str[0]);
	}
	while (str[i])
	{
		res = ft_strncmp(&(str[i]), to_find, len);
		if (res == 0)
			return ((char *)&(str[i]));
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:08:54 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:51:28 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				k;

	i = 0;
	if (find[0] == '\0')
		return ((char *)&str[0]);
	while (str[i] && i < len)
	{
		j = i;
		k = 0;
		while (str[j] == find[k] && find[k] && j < len)
		{
			k++;
			j++;
		}
		if (find[k] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

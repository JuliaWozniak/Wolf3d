/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:46:08 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:46:35 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (len == 0)
		return (str1);
	while (str1[i])
		i++;
	while ((str1[i] = str2[j]) && j < len && str2[j])
	{
		i++;
		j++;
	}
	if (j == len)
		str1[i] = '\0';
	return (str1);
}

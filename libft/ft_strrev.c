/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:36:21 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/17 11:36:26 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char **str)
{
	size_t	i;
	size_t	j;
	char	temp;
	char	*a;

	if (str == NULL || *str == NULL)
		return ;
	a = *str;
	i = 0;
	j = ft_strlen(*str) - 1;
	while (a[i] && i < j)
	{
		temp = a[i];
		a[i++] = a[j];
		a[j--] = temp;
	}
}

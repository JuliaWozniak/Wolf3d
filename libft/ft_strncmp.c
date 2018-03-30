/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:48:32 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:48:46 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t i;

	i = 0;
	if (num == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < num)
		i++;
	if (i == num && s1[i - 1] == s2[i - 1])
		return (0);
	else
		return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}

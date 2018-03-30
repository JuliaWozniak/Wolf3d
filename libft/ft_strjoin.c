/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:34:55 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:35:20 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		num1;
	int		num2;
	char	*nstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	num1 = ft_strlen(s1);
	num2 = ft_strlen(s2);
	nstr = (char *)malloc(num1 + num2 + 1);
	if (nstr)
	{
		ft_strcpy(nstr, s1);
		ft_strcpy((nstr + num1), s2);
	}
	return (nstr);
}

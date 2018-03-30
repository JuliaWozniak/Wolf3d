/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:43:15 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 15:45:02 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	long int	num;
	int			nd;
	int			sign;
	char		*res;

	num = n;
	if ((sign = n) < 0)
		num = -num;
	nd = ft_count_digits(num);
	nd = (sign < 0) ? nd + 1 : nd;
	res = (char *)malloc(nd + 1);
	if (res)
	{
		res[nd] = '\0';
		if (num == 0)
			res[--nd] = '0';
		num *= 10;
		while (nd-- && (num /= 10))
			res[nd] = num % 10 + '0';
		if (sign < 0)
			res[nd] = '-';
	}
	return (res);
}

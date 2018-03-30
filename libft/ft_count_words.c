/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:58:34 by jwozniak          #+#    #+#             */
/*   Updated: 2018/02/05 09:58:36 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	state;
	int	words;

	i = 0;
	state = OUT;
	words = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			state = OUT;
		if (state == OUT && s[i] != c)
		{
			state = IN;
			words++;
		}
		i++;
	}
	return (words);
}

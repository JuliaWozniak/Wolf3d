/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:37:37 by jwozniak          #+#    #+#             */
/*   Updated: 2018/01/20 13:39:54 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_end(const char *start, char c)
{
	while (*start && *start != c)
		start++;
	return ((char *)--start);
}

static char	*new_word(const char *start, const char *end)
{
	int		i;
	char	*nw;

	i = 0;
	nw = (char *)malloc(end - start + 1);
	if (nw == NULL)
		return (NULL);
	while (start <= end)
		nw[i++] = *start++;
	nw[i] = '\0';
	return (nw);
}

static int	free_space(char **res, int n)
{
	while (n--)
		free(res[n]);
	free(res);
	res = NULL;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*curr;
	char	**res;
	char	*nw;
	int		words;
	int		i;

	words = ft_count_words(s, c);
	i = 0;
	if (!s || (res = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	res[words] = NULL;
	while (*s)
	{
		if (*s != c && *s != '\0')
		{
			curr = find_end(s, c);
			nw = new_word(s, curr);
			s = curr;
			if (nw == NULL && (free_space(res, i) == 1))
				return (NULL);
			res[i++] = nw;
		}
		s++;
	}
	return (res);
}

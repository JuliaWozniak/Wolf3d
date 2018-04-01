/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:10:45 by jwozniak          #+#    #+#             */
/*   Updated: 2018/04/01 14:10:47 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	verline(t_img *img, int x, int y, int line)
{
	int		color;
	int		start;
	int		end;

	if (line == FLOOR)
	{
		color = 0x6dcfed;
		end = y;
		start = 0;
	}
	else
	{
		start = y;
		end = HEIGHT;
		color = 0x03bf23;
	}
	while (start <= end)
	{
		set_pixel(img, x, start, color);
		start++;
	}
}

t_line	init_line(double dist)
{
	t_line line;

	line.height = (int)(HEIGHT / dist);
	line.start = -line.height / 2 + HEIGHT / 2;
	line.start = (line.start < 0) ? 0 : line.start;
	line.end = line.height / 2 + HEIGHT / 2;
	line.end = (line.end >= HEIGHT) ? HEIGHT - 1 : line.end;
	return (line);
}

int		show_error(char *reason)
{
	ft_putendl(reason);
	exit(1);
}

int		check_array(t_glob *g, int x, int y)
{
	if (x <= 0.5 || x >= (double)WIDTH - 0.2)
		return (1);
	if (y <= 0.5 || y >= (double)HEIGHT - 0.2)
		return (1);
	return (g->arr[x + g->width * y]);
}

void	remove_rubbish(char **words, char *str)
{
	int i;

	i = -1;
	while (words[++i])
	{
		free(words[i]);
		words[i] = NULL;
	}
	free(str);
	str = NULL;
	free(words);
	words = NULL;
}

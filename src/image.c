/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:10:58 by jwozniak          #+#    #+#             */
/*   Updated: 2018/04/01 14:11:00 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIDTH) * 4)) = color;
}

void	clear_image(t_glob *g)
{
	int size;

	size = WIDTH * HEIGHT * 4;
	ft_bzero(g->img->ptr, size);
}

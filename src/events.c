/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:10:31 by jwozniak          #+#    #+#             */
/*   Updated: 2018/04/01 14:10:35 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	move(t_glob *g, int key)
{
	double	old;

	if (key == 126)
	{
		old = g->posX;
		g->posX += g->dirX;
		if (check_array(g, g->posX, g->posY) != 0)
			g->posX = old;
		old = g->posY;
		g->posY += g->dirY;
		if (check_array(g, g->posX, g->posY) != 0)
			g->posY = old;
	}
	else if (key == 125)
	{
		old = g->posX;
		g->posX -= g->dirX;
		if (check_array(g, (int)g->posX, (int)g->posY) != 0)
			g->posX = old;
		old = g->posY;
		g->posY -= g->dirY;
		if (check_array(g, (int)g->posX, (int)g->posY) != 0)
			g->posY = old;
	}
}

void	rotate(t_glob *g, int key)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == 123)
	{
		old_dir_x = g->dirX;
		g->dirX = g->dirX * cos(ROT) - g->dirY * sin(ROT);
		g->dirY = old_dir_x * sin(ROT) + g->dirY * cos(ROT);
		old_plane_x = g->planeX;
		g->planeX = g->planeX * cos(ROT) - g->planeY * sin(ROT);
		g->planeY = old_plane_x * sin(ROT) + g->planeY * cos(ROT);
	}
	else if (key == 124)
	{
		old_dir_x = g->dirX;
		g->dirX = g->dirX * cos(-ROT) - g->dirY * sin(-ROT);
		g->dirY = old_dir_x * sin(-ROT) + g->dirY * cos(-ROT);
		old_plane_x = g->planeX;
		g->planeX = g->planeX * cos(-ROT) - g->planeY * sin(-ROT);
		g->planeY = old_plane_x * sin(-ROT) + g->planeY * cos(-ROT);
	}
}

int		key_pressed(int key, t_glob *g)
{
	if (key == 53)
		exit(1);
	if (key == 126 || key == 125)
		move(g, key);
	else if (key == 123 || key == 124)
		rotate(g, key);
	else
	{
		printf("%i\n", key);
		return (0);
	}
	clear_image(g);
	render_walls(g);
	return (0);
}

int		exit_wolf(void *par)
{
	par = NULL;
	exit(0);
	return (0);
}

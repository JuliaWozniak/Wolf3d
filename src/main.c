/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:11:30 by jwozniak          #+#    #+#             */
/*   Updated: 2018/04/01 14:11:32 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	get_steps(t_cast *c, int x, t_glob *g)
{
	c->cameraX = 2 * x / (double)WIDTH - 1;
	c->rayDirX = g->dirX + g->planeX * c->cameraX;
	c->rayDirY = g->dirY + g->planeY * c->cameraX;
	c->mapX = (int)g->posX;
	c->mapY = (int)g->posY;
	c->deltaDistX = fabs(1 / c->rayDirX);
	c->deltaDistY = fabs(1 / c->rayDirY);
	c->stepX = (c->rayDirX < 0) ? -1 : 1;
	c->stepY = (c->rayDirY < 0) ? -1 : 1;
	if (c->rayDirX < 0)
		c->sideDistX = (g->posX - c->mapX) * c->deltaDistX;
	else
		c->sideDistX = (c->mapX + 1.0 - g->posX) * c->deltaDistX;
	if (c->rayDirY < 0)
		c->sideDistY = (g->posY - c->mapY) * c->deltaDistY;
	else
		c->sideDistY = (c->mapY + 1.0 - g->posY) * c->deltaDistY;
}

double	get_distance(t_glob *g, t_cast *c)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (c->sideDistX < c->sideDistY)
		{
			c->sideDistX += c->deltaDistX;
			c->mapX += c->stepX;
			c->side = 0;
		}
		else
		{
			c->sideDistY += c->deltaDistY;
			c->mapY += c->stepY;
			c->side = 1;
		}
		if (g->arr[c->mapX + g->width * c->mapY] > 0)
			hit = 1;
	}
	if (c->side == 0)
		return ((c->mapX - g->posX + (1 - c->stepX) / 2) / c->rayDirX);
	else
		return ((c->mapY - g->posY + (1 - c->stepY) / 2) / c->rayDirY);
}

void	draw_wall_segment(t_glob *g, t_cast *c, double dist, int x)
{
	t_line	line;
	t_tex	t;

	line = init_line(dist);
	t.tex_num = g->arr[c->mapX + c->mapY * g->width] % TEXTURES;
	if (c->side == 1)
		t.tex_num = (c->stepY == 1) ? 0 : 1;
	else
		t.tex_num = (c->stepX == 1) ? 2 : 3;
	verline(g->img, x, line.start, FLOOR);
	verline(g->img, x, line.end, SKY);
	if (c->side == 0)
		line.x = g->posY + dist * c->rayDirY;
	else
		line.x = g->posX + dist * c->rayDirX;
	line.x -= floor(line.x);
	t.tex_x = (int)(line.x * (double)TEX_W);
	if (c->side == 0 && c->rayDirX > 0)
		t.tex_x = TEX_W - t.tex_x - 1;
	if (c->side == 1 && c->rayDirY < 0)
		t.tex_x = TEX_W - t.tex_x - 1;
	draw_tex_pattern(g, line, t, x);
}

void	render_walls(t_glob *g)
{
	int		x;
	double	distance;

	x = 0;
	while (x < WIDTH)
	{
		get_steps(g->c, x, g);
		distance = get_distance(g, g->c);
		draw_wall_segment(g, g->c, distance, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx->m_p, g->mlx->w_p, g->img->image, 0, 0);
}

int		main(int argc, char **argv)
{
	t_glob	*g;
	int		fd;
	int		*map;

	if (argc < 2)
		return (show_error("Give me a map, please."));
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		show_error("It is a directory");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (show_error("Check filename, please"));
	g = init_glob();
	map = read_map(fd, 0, g);
	g->arr = map;
	get_spawn_position(g);
	init_textures(g);
	render_walls(g);
	mlx_put_image_to_window(g->mlx->m_p, g->mlx->w_p, g->img, 0, 0);
	mlx_key_hook(g->mlx->w_p, key_pressed, g);
	mlx_hook(g->mlx->w_p, 17, 1L << 17, exit_wolf, g);
	mlx_loop(g->mlx->m_p);
}

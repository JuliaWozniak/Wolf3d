/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:12:01 by jwozniak          #+#    #+#             */
/*   Updated: 2018/04/01 14:12:05 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	draw_tex_pattern(t_glob *g, t_line line, t_tex t, int x)
{
	int y;
	int d;
	int tex_y;
	int color;

	y = line.start;
	while (y < line.end)
	{
		d = y * 256 - HEIGHT * 128 + line.height * 128;
		tex_y = ((d * TEX_H) / line.height) / 256;
		color = *(int *)(g->texs[t.tex_num].ptr +
			((t.tex_x + tex_y * TEX_W) * 4));
		set_pixel(g->img, x, y, color);
		y++;
	}
}

void	init_textures(t_glob *g)
{
	static char	*texs[TEXTURES] = {
		"textures/otherWall.xpm",
		"textures/wet_wood.xpm",
		"textures/grayWall.xpm",
		"textures/red_bricks.xpm"
	};
	int			i;

	i = 0;
	g->texs = (t_img *)ft_memalloc(sizeof(t_img) * TEXTURES);
	while (i < TEXTURES)
	{
		g->texs[i].image = mlx_xpm_file_to_image(g->mlx->m_p, texs[i],
			&g->texs[i].width, &g->texs[i].height);
		g->texs[i].ptr = mlx_get_data_addr(g->texs[i].image,
			&g->texs[i].bpp, &g->texs[i].strd, &g->texs[i].endn);
		i++;
	}
}

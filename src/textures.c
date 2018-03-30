#include "../wolf.h"


void init_textures(t_glob *g)
{
	static char *texs[TEXTURES] = {
		"textures/otherWall.xpm",
		"textures/wet_wood.xpm",
		"textures/grayWall.xpm",
		"textures/red_bricks.xpm"
	};
	int i;
	
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
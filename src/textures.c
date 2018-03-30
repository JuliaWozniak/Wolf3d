#include "../wolf.h"

// t_img	*create_xpm_image(char *name, t_mlx *mlx)
// {
// 	t_img		*img;

// 	img = ft_memalloc(sizeof(t_img));
// 	img->image = mlx_xpm_file_to_image(mlx->m_p, name, &img->width,
// 			&img->height);
// 	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->strd,
// 		&img->endn);
// 	img->bpp /= 8;
// 	img->width = img->strd / img->bpp;
// 	img->height = img->strd / img->bpp;
// 	return (img);
// }

// void init_textures(t_glob *g)
// {
// 	static char *texs[TEXTURES] = {
// 		"textures/metal.xpm", NULL
// 	};
// 	int i;
// 	t_img *xpm;

// 	i = 0;
// 	while (texs[i])
// 	{
// 		xpm = create_xpm_image(texs[i], g->mlx);
// 		if (xpm == NULL)
// 			printf("wrong smth\n");
// 		g->texs[i]->ptr = xpm;
// 		if (g->texs[i]->ptr == NULL)
// 			printf("what\n");
// 		i++;
// 	}
// }

// t_img	*create_xpm_image(char *name, t_mlx *mlx)
// {
// 	t_img		*img;

// 	img = ft_memalloc(sizeof(t_img));
// 	img->image = mlx_xpm_file_to_image(mlx->m_p, name, &img->width,
// 			&img->height);
// 	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->strd,
// 		&img->endn);
// 	img->bpp /= 8;
// 	img->width = img->strd / img->bpp;
// 	img->height = img->strd / img->bpp;
// 	return (img);
// }

void init_textures(t_glob *g)
{
	static char *texs[TEXTURES] = {
		"textures/otherWall.xpm",
		"textures/wet_wood.xpm",
		"textures/grayWall.xpm"
	};
	int i;
	//t_img *xpm;

printf("here 0\n");
	i = 0;
	g->texs = (t_img *)ft_memalloc(sizeof(t_img) * TEXTURES); // multiplied .....
	while (i < TEXTURES)
	{
	 	g->texs[i].image = mlx_xpm_file_to_image(g->mlx->m_p, texs[i], 
	 		&g->texs[i].width, &g->texs[i].height);
	 	if (g->texs[i].image == NULL)
			printf("what\n");
		g->texs[i].ptr = mlx_get_data_addr(g->texs[i].image, 
			&g->texs[i].bpp, &g->texs[i].strd, &g->texs[i].endn);
		if (g->texs[i].ptr == NULL)
			printf("whatwhat\n");
		i++;
	}
	i = 100;
	while (i--)
	{
		int color;

		color = (int)(g->texs[0].image + i * 4);
		//*(int *)(img->ptr + ((x + y * WIDTH) * 4))
		if (color != 0)
		{
			set_pixel(g->img, i, 0, color);
			//printf("%i\n", color);
		}
	}
	printf("here 10\n");
}
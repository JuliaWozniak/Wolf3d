#include "../wolf.h"

t_img	*create_xpm_image(char *name, t_mlx *mlx)
{
	t_img		*img;

	img = ft_memalloc(sizeof(t_img));
	img->image = mlx_xpm_file_to_image(mlx->m_p, name, &img->width,
			&img->height);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->strd,
		&img->endn);
	img->bpp /= 8;
	img->width = img->strd / img->bpp;
	img->height = img->strd / img->bpp;
	return (img);
}

void init_textures(t_glob *g)
{
	static char *texs[TEXTURES] = {
		"textures/metal.xpm", NULL
	};
	int i;
	t_img *xpm;

	i = 0;
	while (texs[i])
	{
		xpm = create_xpm_image(texs[i], g->mlx);
		if (xpm == NULL)
			printf("wrong smth\n");
		g->texs[i] = xpm;
		i++;
	}
}

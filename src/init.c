#include "../wolf.h"

t_img *create_image(void *mlx)
{
  t_img *img;

  img = (t_img *)ft_memalloc(sizeof(t_img));
  img->image = mlx_new_image(mlx, WIDTH, HEIGHT);
  img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->strd, &img->endn);
  return (img);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->m_p = mlx_init();
	mlx->w_p = mlx_new_window(mlx->m_p, WIDTH, HEIGHT, "WOLF3D");
	return (mlx);
}

void get_spawn_position(t_glob *g)
{
  int i;
  int j;

  j = g->height;
  while (j--)
  {
    i = g->width;
    while (i--)
    {
      if (g->arr[i + g->width * j] == 0)
      {
        if (g->arr[i + g->width * j] == 0
          && g->arr[i - 1 + g->width * j] == 0
          && g->arr[i - 1 + g->width * (j - 1)] == 0)
{
          g->posX = i;
             g->posY = j;
            return ;
}
      }
    }
  }
  show_error("please, create 2 x 2 free space for spawn point");
}

t_glob    *init_glob(void)
{
  t_glob  *g;

  g = (t_glob *)ft_memalloc(sizeof(t_glob));
  g->mlx = init_mlx();
  // g->c = (t_cast *)ft_memalloc(sizeof(t_cast));
  g->img = create_image(g->mlx->m_p);
  g->dirX = -1; 
  g->dirY = 0;
  g->planeX = 0;
  g->planeY = 0.66;
  return (g);
}

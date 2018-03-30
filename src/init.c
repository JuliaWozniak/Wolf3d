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

t_glob    *init_glob(void)
{
  t_glob  *g;

  g = (t_glob *)ft_memalloc(sizeof(t_glob));
  g->mlx = init_mlx();
  g->c = (t_cast *)ft_memalloc(sizeof(t_cast));
  g->img = create_image(g->mlx->m_p);
  g->dirX = -1; 
  g->dirY = 0;
  g->planeX = 0;
  g->planeY = 0.66;
  //g->textures = (int *)ft_memalloc(4 * sizeof(int) * TEX_H * TEX_W);

  return (g);
}

void generate_textures(t_glob *g)
{
  for (int x = 0; x < TEX_W; x++)
  {
    for (int y = 0; y < TEX_H; y++)
   {
   // int xorcolor = (x * 256 / TEX_W) ^ (y * 256 / TEX_H);
    //int xcolor = x * 256 / texWidth;
   // int ycolor = y * 256 / TEX_H;
    //int xycolor = y * 128 / TEX_H + x * 128 / TEX_W;
    g->textures[TEX_W * y + x] = 65536 * 254 * (x != y && x != TEX_W - y);
     //flat red texture with black cross
    printf("%i\n", g->textures[TEX_W * y + x]);
    //  g->textures[TEX_W * y + x + TEX_W * TEX_H] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    // // g->textures[TEX_W * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    //  g->textures[TEX_W * y + x + 2 * TEX_W * TEX_H] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    // // g->textures[TEX_W * y + x] = 256 * xorcolor; //xor green
    //  g->textures[TEX_W * y + x + 3 * TEX_W * TEX_H] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    // // g->textures[TEX_W * y + x] = 65536 * ycolor; //red gradient
    //  //g->textures[TEX_W * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
    }
  }
}



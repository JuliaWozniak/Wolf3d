#ifndef WOLF_H
# define WOLF_H

#include <stdlib.h>
#include <stdio.h>
#include "./minilibx_macos/mlx.h"
#include "./libft/includes/libft.h"
#include <math.h>
#include <unistd.h>

#define WIDTH 900
#define HEIGHT 700
#define MOVE 0.05
#define ROT 0.3
#define TEX_W 64
#define TEX_H 64
#define TEXTURES 2

typedef struct	s_img
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		strd;
	int		endn;
  int width;
  int height;
}				t_img;

typedef struct	s_mlx
{
	void	*m_p;
	void	*w_p;
}				t_mlx;

typedef struct s_cast
{
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double sideDistX;
    double sideDistY;
    double perpWallDist;
    int stepX;
    int stepY;
    int hit;
    int side;
    double deltaDistX;
    double deltaDistY;
}               t_cast;

typedef struct  s_glob
{
  t_mlx *mlx;
  t_img *img;
  int *arr;
  double posX;
  double posY;
  double dirY;
  double dirX;
  double planeX;
  double planeY;
  t_img *texs[TEXTURES];
  int textures[TEX_W * TEX_H];
  t_cast *c;
  int width;
  int height;
}       t_glob;

void generate_textures(t_glob *g);
t_glob    *init_glob(void);
void init_map(t_glob *g);
t_mlx *init_mlx(void);
int   key_pressed(int key, t_glob *g);
int check_array(t_glob *g, int x, int y);
void render_walls(t_glob *g);
void  clear_image(t_glob *g);
void  set_pixel(t_img *img, int x, int y, int color);
int check_array(t_glob *g, int x, int y);
int   show_error(char *reason);
void verLine(t_img *img, int x, int start, int end, int color);
int *read_map(int fd, int res, t_glob *g);
void init_textures(t_glob *g);

#endif
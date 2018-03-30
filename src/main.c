#include "../wolf.h"


void get_steps(t_cast *c, int x, t_glob *g)
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

double get_distance(t_glob *g, t_cast *c)
{
  double perpWallDist;
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
        perpWallDist = (c->mapX - g->posX + (1 - c->stepX) / 2) / c->rayDirX;
      else
        perpWallDist = (c->mapY - g->posY + (1 - c->stepY) / 2) / c->rayDirY; 
      return (perpWallDist);
}

void draw_segment(t_glob *g, t_cast *c, double dist, int x)
{
  int lineHeight;
  int drawStart;
  int drawEnd;

  lineHeight = (int)(HEIGHT / dist);
  drawStart = -lineHeight / 2 + HEIGHT / 2;
  drawStart = (drawStart < 0) ? 0 : drawStart;
  drawEnd = lineHeight / 2 + HEIGHT / 2;
  drawEnd = (drawEnd >= HEIGHT) ? HEIGHT - 1 : drawEnd;
      if (c->side == 1)
      {
        if (c->stepY == 1)
          verLine(g->img, x, drawStart, drawEnd, 0x3d4c3f);
        else
          verLine(g->img, x, drawStart, drawEnd, 0x4c4b46);
      }
      else
      {
        if (c->stepX == 1)
          verLine(g->img, x, drawStart, drawEnd, 0xc62200);
       else
          verLine(g->img, x, drawStart, drawEnd, 0xfe9b00);
      }
      verLine(g->img, x, 0, drawStart, 0x6dcfed);
      verLine(g->img, x, drawEnd, HEIGHT, 0x03bf23);
}


void render_walls(t_glob *g)
{
  int x;
  double distance;

  x = 0;
  while (x < WIDTH)
  {
    get_steps(g->c, x, g);
    distance = get_distance(g, g->c);
    draw_segment(g, g->c, distance, x);
    x++;
  }
  mlx_put_image_to_window(g->mlx->m_p, g->mlx->w_p, g->img->image, 0, 0);
}

void get_spawn_position(t_glob *g)
{
  int i;
  int j;

  printf("%i %i\n", g->width, g->height);
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


int main(int argc, char **argv)
{
  t_glob *g;
  int fd;
  int *map;

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
  generate_textures(g);
  render_walls(g);
  mlx_put_image_to_window(g->mlx->m_p, g->mlx->w_p, g->img, 0, 0);
  mlx_key_hook(g->mlx->w_p, key_pressed, g);  
  mlx_loop(g->mlx->m_p);
}

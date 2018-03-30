#include "../wolf.h"

void verLine(t_img *img, int x, int start, int end, int color)
{
  while (start <= end)
  {
    set_pixel(img, x, start, color);
    start++;
  }
}

int   show_error(char *reason)
{
  ft_putendl(reason);
  exit(1);
}

int check_array(t_glob *g, int x, int y)
{
  if (x <= 0.5 || x >= (double)WIDTH - 0.2)
    return (1);
  if (y <= 0.5 || y >= (double)HEIGHT - 0.2)
    return (1);
  return (g->arr[x + g->width * y]);
}
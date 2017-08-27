#include "fractol.h"

static void     ft_julia_putpix(t_fract *fract, t_julia *jul, int x, int y)
{
  (void) fract;
  (void) x;
  (void) y;
  if (jul->i == jul->iter_max)
    // ft_put_pixel_to_image(fract->imgchar, x, y, 0xFF6666);
    printf("ok 1\n");
  else
    printf("ok 2\n");
    // ft_put_pixel_to_image(fract->imgchar, x, y, ft_color(0, 0, jul->i
      //  * 255 / jul->iter_max ));
}

static void     ft_julia_cal_z_point(t_fract *fract, t_julia *jul, int x, int y)
{
    double      tmp;
    double      stock;

    tmp = jul->z_r;
    jul->z_r = jul->z_r * jul->z_r - jul->z_i * jul->z_i + jul->c_r;
    jul->z_i = 2 * jul->z_i * tmp + jul->c_i;
    jul->i = jul->i + 1;
    stock = jul->z_r * jul->z_r + jul->z_i * jul->z_i;
    while (stock < 4 && jul->i < jul->iter_max)
    {
      tmp = jul->z_r;
      jul->z_r = jul->z_r * jul->z_r - jul->z_i * jul->z_i + jul->c_r;
      jul->z_i = 2 * jul->z_i * tmp + jul->c_i;
      jul->i = jul->i + 1;
      stock = jul->z_r * jul->z_r + jul->z_i * jul->z_i;
    }
    ft_julia_putpix(fract, jul, x, y);
}

static void     ft_julia_search_z_point(t_fract *fract, t_julia *jul)
{
  int           x;
  int           y;

  x = 0;
  while(x < jul->x_image)
  {
    y = 0;
    while (y < jul->y_image)
    {
      jul->i = 0;
      jul->z_r = x / jul->zoom + jul->x_one;
      jul->z_i = y / jul->zoom + jul->y_one;
      ft_julia_cal_z_point(fract, jul, x, y);
      if (y > fract->y_sizewin)
        break ;
      y++;
    }
    if (x > fract->x_sizewin)
      break ;
    x++;
  }
}

static void     ft_julia_image(t_fract *fract)
{
  fract->julia.x_image = (fract->julia.x_two - fract->julia.x_one)
    * fract->julia.zoom;
  fract->julia.y_image = (fract->julia.y_two - fract->julia.y_one)
    * fract->julia.zoom;
  fract->image = mlx_new_image(fract->mlx, fract->julia.x_image + 1,
    fract->julia.y_image);
  fract->imgchar = mlx_get_data_addr(fract->image, &(fract->mlximgbpp),
    &(fract->mlximgsize), &(fract->mlximgendian));
  ft_julia_search_z_point(fract, &(fract->julia));
}

void            ft_julia_fract(t_fract *fract)
{
  fract->x_sizewin = 600;
  fract->y_sizewin = 600;
  fract->julia.x_one = -1.5;
  fract->julia.x_two = 1.5;
  fract->julia.y_one = -1.5;
  fract->julia.y_two = 1.5;
  fract->julia.zoom = 100;
  fract->julia.iter_max = 150;
  fract->julia.c_r = 0.285;
  fract->julia.c_i = 0.01;
  fract->julia.block = 0;
  fract->mlx = mlx_init();
  fract->win = mlx_new_window(fract->mlx, fract->x_sizewin, fract->y_sizewin,
    "FRACTOL");
  ft_julia_image(fract);
  mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
  mlx_loop(fract->mlx);
}

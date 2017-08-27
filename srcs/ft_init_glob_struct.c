#include "fractol.h"

static void       ft_fill_struct(t_fract *fract)
{
  fract->x_sizewin = 0;
  fract->y_sizewin = 0;
  fract->mlx = NULL;
  fract->win = NULL;
  fract->image = NULL;
  fract->imgchar = NULL;
}

t_fract           *ft_init_glob_struct(void)
{
  static t_fract  *fract = NULL;
  static int      check = 0;

  if (fract == NULL && check == 0)
  {
    if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
      return (NULL);
    check = 1;
    ft_fill_struct(fract);
  }
  return (fract);
}

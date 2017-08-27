#include "fractol.h"
static void  ft_start_fractol(t_fract *fract, char **av)
{
  if (ft_strcmp(av[1], "julia") == 0)
    ft_julia_fract(fract);
  else if (ft_strcmp(av[1], "mandelbrot") == 0)
    // ft_mandel_fract(fract);
    printf("ok\n");
  else if (ft_strcmp(av[1], "burningship") == 0)
    printf("ok\n");
    // ft_burning_fract(fract);
  return;
}


int         main(int argc, char **argv)
{
  if (ft_parser(argc, argv) == -1)
    return (EXIT_FAILURE);
  ft_start_fractol(ft_init_glob_struct(), argv);
  return (0);
}

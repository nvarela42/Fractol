#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <errno.h>

# ifdef __linux
# else
# endif

typedef struct s_fract    t_fract;
typedef struct s_julia    t_julia;
typedef struct s_mand     t_mand;
typedef struct s_burn     t_burn;

struct                     s_julia
{
  double					         x_one;
  double						       x_two;
  double						       y_one;
  double				        	 y_two;
  double				       		 zoom;
  double			          	 iter_max;
  double			         		 x_image;
  double						       y_image;
  double						       c_r;
  double						       c_i;
  double						       z_r;
  double						       z_i;
  double						       i;
  int							         block;
};

 struct                     s_mand
{
  double						        x_one;
  double						        x_two;
  double						        y_one;
  double				        		y_two;
  double				         		zoom;
  double			           		iter_max;
  double			          		x_image;
  double						        y_image;
  double						        c_r;
  double						        c_i;
  double						        z_r;
  double						        z_i;
  double						        i;
  int							          block;
};

struct                       s_burn
{
  double						        x_one;
  double						        x_two;
  double						        y_one;
  double				        		y_two;
  double				         		zoom;
  double			           		iter_max;
  double			          		x_image;
  double						        y_image;
  double						        c_r;
  double						        c_i;
  double						        z_r;
  double						        z_i;
  double						        i;
  int							          block;
};

struct                      s_fract
{
  int                       x_sizewin;
  int                       y_sizewin;
  int                       x_sizewin_bis;
  int                       y_sizewin_bis;
  void                      *mlx;
  void                      *win;
  void                      *image;
  char                      *imgchar;
  int                       mlximgbpp;
  int                       mlximgsize;
  int                       mlximgendian;
  t_julia                   julia;
  t_mand                    mandel;
  t_burn                    burning;
};

int                         ft_parser(int ac, char **av);
t_fract                     *ft_init_glob_struct();
void                        ft_julia_fract(t_fract *fract);
void                        ft_put_pixel_to_image(t_fract *fract, int x, int y, int color);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:38:58 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/14 20:48:51 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <errno.h>

# define ESCAPEKEY 53
# define UPKEY 126
# define DOWNKEY 125
# define LEFTKEY 123
# define RIGHTKEY 124
# define ZOOMPLUS 4
# define KEYPLUS 69
# define KEYMINUS 78
# define ZOOMMINUS 5
# define RIGHTCLICK 1
# define TABCOLSIZE 4

typedef struct s_fract	t_fract;
typedef struct s_julia	t_julia;
typedef struct s_mand	t_mand;
typedef struct s_color	t_color;

struct					s_julia
{
	double				x_one;
	double				x_two;
	double				y_one;
	double				y_two;
	double				zoom;
	double				iter_max;
	double				x_image;
	double				y_image;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				i;
	int					block;
};

struct					s_mand
{
	double				x_one;
	double				x_two;
	double				y_one;
	double				y_two;
	double				zoom;
	double				iter_max;
	double				x_image;
	double				y_image;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				i;
	int					block;
};

struct					s_fract
{
	int					x_sizewin;
	int					y_sizewin;
	int					x_sizewin_bis;
	int					y_sizewin_bis;
	void				*mlx;
	void				*win;
	void				*image;
	char				*imgchar;
	int					mlximgbpp;
	int					mlximgsize;
	int					mlximgendian;
	int					is_burn;
	int					is_jul;
	int					is_mand;
	t_color				*col;
	t_julia				julia;
	t_mand				mand;
};

struct					s_color
{
	int					r;
	int					g;
	int					b;
};

int						ft_parser(int ac, char **av);
t_fract					*ft_init_glob_struct();
void					ft_julia_fract(t_fract *fract);
void					ft_put_pixel_to_image(t_fract *fract, int x, int y,
						int color);
int						ft_search_rgb(int r, int g, int b);
void					ft_mandel_fract(t_fract *fract);
void					ft_mandel_image(t_fract *fract);
int						ft_julia_mouse_position(int x, int y, void *param);
int						ft_julia_mouse_button(int button, int x, int y,
						void *param);
void					ft_julia_image(t_fract *fract);
int						ft_key_fonction(int keycode, void *param);
int						ft_mandel_mouse_position(int x, int y, void *param);
int						ft_mandel_mouse_button(int button, int x, int y,
						void *param);
int						quit_cross(t_fract *fract);
void					ft_julia_dezoom(int x, int y, t_julia *jul);
void					ft_julia_zoom(int x, int y, t_julia *jul);
void					ft_mandel_zoom(int x, int y, t_mand *mand);
void					ft_mandel_dezoom(int x, int y, t_mand *mand);
t_color					*ft_lstco();
#endif

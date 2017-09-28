/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:38:58 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 18:19:00 by nvarela          ###   ########.fr       */
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
# define RESETKEY 15
# define BASIC_COLTYPE 82
# define COLTYPE_ONE 83
# define COLTYPE_TWO 84

typedef struct s_fract	t_fract;
typedef struct s_type	t_type;
typedef struct s_color	t_color;

struct					s_type
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
	int					color_type;
	t_color				*col;
	t_type				type;
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
int						ft_search_rgb(int r, int g, int b);
void					ft_mandel_fract(t_fract *fract);
void					ft_mand_search_z_point(t_fract *fract, t_type *mand);
int						ft_julia_mouse_position(int x, int y, void *param);
int						ft_mouse_button(int button, int x, int y, void *param);
void					ft_julia_search_z_point(t_fract *fract, t_type *jul);
int						ft_key_fonction(int keycode, void *param);
int						quit_cross(t_fract *fract);
void					ft_dezoom(int x, int y, t_type *jul);
void					ft_zoom(int x, int y, t_type *jul);
void					ft_resetkey(t_fract *tmp);
void					ft_movekey(int key, t_fract *tmp);
void					ft_zoomkey(int key, t_fract *tmp);
t_color					*ft_lstco(int type);
void					ft_color_type(int key, t_fract *tmp);
t_color					*ft_basic_color();
t_color					*ft_col_type_one();
t_color					*ft_col_type_two();
void					ft_reset_julia(t_fract *tmp);
void					ft_reset_mandel(t_fract *tmp);
void					ft_put_image(t_fract *fract, t_type *jul, int x, int y);
void					ft_create_image(t_fract *fract);
void					ft_free_struct(t_fract **fract);
void					ft_usage_on_image(t_fract *fract);
void					ft_usage_on_console(void);

#endif

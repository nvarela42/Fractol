/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_fract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:04:56 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 17:38:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_julia_cal_z_point(t_fract *fract, t_type *jul, int x, int y)
{
	double		tmp;
	double		stock;

	tmp = jul->z_r;
	jul->z_r = jul->z_r * jul->z_r - jul->z_i * jul->z_i + jul->c_r;
	jul->z_i = (jul->z_i + jul->z_i) * tmp + jul->c_i;
	jul->i = jul->i + 1;
	stock = jul->z_r * jul->z_r + jul->z_i * jul->z_i;
	while (stock < 4 && jul->i < jul->iter_max)
	{
		tmp = jul->z_r;
		jul->z_r = jul->z_r * jul->z_r - jul->z_i * jul->z_i + jul->c_r;
		jul->z_i = (jul->z_i + jul->z_i) * tmp + jul->c_i;
		jul->i = jul->i + 1;
		stock = jul->z_r * jul->z_r + jul->z_i * jul->z_i;
	}
	ft_put_image(fract, jul, x, y);
}

void			ft_julia_search_z_point(t_fract *fract, t_type *jul)
{
	int			x;
	int			y;

	x = 0;
	while (x < fract->x_sizewin)
	{
		y = 0;
		while (y < fract->y_sizewin)
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

void			ft_julia_fract(t_fract *fract)
{
	fract->type.x_one = -1.8;
	fract->type.x_two = 1.5;
	fract->type.y_one = -1.8;
	fract->type.y_two = 1.5;
	fract->type.zoom = 100;
	fract->type.iter_max = 50;
	fract->type.c_r = 0.285;
	fract->type.c_i = 0.01;
	fract->type.block = 0;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, fract->x_sizewin, fract->y_sizewin,
	"FRACTOL");
	ft_create_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	mlx_hook(fract->win, 17, 0, quit_cross, fract);
	mlx_hook(fract->win, 6, (1L << 6), ft_julia_mouse_position, fract);
	mlx_key_hook(fract->win, ft_key_fonction, fract);
	mlx_mouse_hook(fract->win, ft_mouse_button, fract);
	mlx_loop(fract->mlx);
}

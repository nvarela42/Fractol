/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:06:25 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 16:57:28 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_mand_cal_z_point(t_fract *fract, t_type *mand, int x, int y)
{
	double		tmp;
	double		stock;

	stock = mand->z_r * mand->z_r + mand->z_i * mand->z_i;
	while (stock < 4 && mand->i < mand->iter_max)
	{
		tmp = mand->z_r;
		mand->z_r = mand->z_r * mand->z_r - mand->z_i * mand->z_i + mand->c_r;
		if (fract->is_burn == 1)
			mand->z_r = mand->z_r < 0 ? mand->z_r * -1 : mand->z_r;
		mand->z_i = (mand->z_i + mand->z_i) * tmp + mand->c_i;
		if (fract->is_burn == 1)
			mand->z_i = mand->z_i < 0 ? mand->z_i * -1 : mand->z_i;
		mand->i = mand->i + 1;
		stock = mand->z_r * mand->z_r + mand->z_i * mand->z_i;
	}
	ft_put_image(fract, mand, x, y);
}

void			ft_mand_search_z_point(t_fract *fract, t_type *mand)
{
	int			x;
	int			y;

	x = 0;
	while (x < fract->x_sizewin)
	{
		y = 0;
		while (y < fract->y_sizewin)
		{
			mand->c_r = x / mand->zoom + mand->x_one;
			mand->c_i = y / mand->zoom + mand->y_one;
			mand->z_r = 0;
			mand->z_i = 0;
			mand->i = 0;
			ft_mand_cal_z_point(fract, mand, x, y);
			if (y > fract->y_sizewin)
				break ;
			y++;
		}
		if (x > fract->x_sizewin)
			break ;
		x++;
	}
}

void			ft_mandel_fract(t_fract *fract)
{
	fract->type.x_one = -2.3;
	fract->type.x_two = 0.6;
	fract->type.y_one = -1.8;
	fract->type.y_two = 1.2;
	fract->type.zoom = 100;
	fract->type.iter_max = 30;
	fract->type.block = 0;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, fract->x_sizewin, fract->y_sizewin,
		"FRACTOL");
	ft_create_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	mlx_hook(fract->win, 17, 0, quit_cross, fract);
	mlx_key_hook(fract->win, ft_key_fonction, fract);
	mlx_mouse_hook(fract->win, ft_mouse_button, fract);
	mlx_loop(fract->mlx);
}

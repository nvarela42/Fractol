/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:06:25 by nvarela           #+#    #+#             */
/*   Updated: 2017/08/31 18:45:13 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_mand_putpix(t_fract *fract, t_mand *mand, int x, int y)
{
	if (mand->i == mand->iter_max)
		ft_put_pixel_to_image(fract, x, y, 0xC5FCAC);
	else
		ft_put_pixel_to_image(fract, x, y, ft_search_rgb(0, 0, mand->i
			* 255 / mand->iter_max));
}

static void		ft_mand_cal_z_point(t_fract * fract, t_mand *mand, int x, int y)
{
	double		tmp;
	double		stock;

	stock = mand->z_r * mand->z_r + mand->z_i * mand->z_i;
	while (stock < 4 && mand->i < mand->iter_max)
	{
		tmp = mand->z_r;
		mand->z_r = mand->z_r * mand->z_r - mand->z_i * mand->z_i + mand->c_r;
		if (fract->burn == 1)
			mand->z_r = mand->z_r < 0 ? mand->z_r * -1 : mand->z_r;
		mand->z_i = 2 * mand->z_i * tmp + mand->c_i;
		if (fract->burn == 1)
			mand->z_i = mand->z_i < 0 ? mand->z_i * -1 : mand->z_i;
		mand->i = mand->i + 1;
		stock = mand->z_r * mand->z_r + mand->z_i * mand->z_i;
	}
	ft_mand_putpix(fract, mand, x, y);
}

static void		ft_mand_search_z_point(t_fract *fract, t_mand *mand)
{
	int			x;
	int			y;

	x = 0;
	while (x < mand->x_image)
	{
		y = 0;
		while (y < mand->y_image)
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

static void		ft_mand_image(t_fract *fract)
{
	fract->mand.iter_max = 400;
	fract->mand.x_image = (fract->mand.x_two - fract->mand.x_one)
		* fract->mand.zoom;
	fract->mand.y_image = (fract->mand.y_two - fract->mand.y_one)
		* fract->mand.zoom;
	fract->image = mlx_new_image(fract->mlx, fract->mand.x_image + 1,
		fract->mand.y_image + 1);
	fract->imgchar =  mlx_get_data_addr(fract->image, &(fract->mlximgbpp),
 		&(fract->mlximgsize), &(fract->mlximgendian));
	ft_mand_search_z_point(fract, &(fract->mand));
}

void			ft_mandel_fract(t_fract *fract)
{
	fract->x_sizewin = 600;
	fract->y_sizewin = 600;
	fract->mand.x_one = -2.1;
	fract->mand.x_two = 0.6;
	fract->mand.y_one = -1.2;
	fract->mand.y_two = 1.2;
	fract->mand.zoom = 100;
	fract->mand.block = 0;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, fract->x_sizewin, fract->y_sizewin,
		"FRACTOL");
	ft_mand_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	// mlx_hook(fract->win, 17, 0, quit_cross, fract);
	 mlx_key_hook(fract->win,ft_escape_key, fract);
	// mlx_mouse_hook(fract->win, mlx_mouse_misc_mend, fract);
	mlx_loop(fract->mlx);
}

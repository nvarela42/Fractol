/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:39:57 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/27 17:52:52 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_julia_dezoom(int x, int y, t_julia *jul)
{
	double            converted_i;
	double            converted_r;

	if (y > 0)
	{
		converted_r = (x / jul->zoom) + jul->x_one;
		converted_i = (y / jul->zoom) + jul->y_one;
		jul->zoom /= 1.1;
		jul->iter_max -= 1;
		jul->x_one = converted_r - (x / jul->zoom);
		jul->y_one = converted_i - (y / jul->zoom);
	}
}

void			ft_julia_zoom(int x, int y, t_julia *jul)
{
	double            converted_i;
	double            converted_r;

	if (y > 0)
	{
		converted_r = (x / jul->zoom) + jul->x_one;
		converted_i = (y / jul->zoom) + jul->y_one;
		jul->zoom *= 1.1;
		jul->iter_max += 1;
		jul->x_one = converted_r - (x / jul->zoom);
		jul->y_one = converted_i - (y / jul->zoom);
	}
}

int				ft_julia_mouse_button(int button, int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *)param;
	if (button == ZOOMPLUS)
		ft_julia_zoom(x, y, &(fract->julia));
	else if (button == ZOOMMINUS)
	{
		if (fract->julia.zoom > 100)
			ft_julia_dezoom(x, y, &(fract->julia));
	}
	else if (button == RIGHTCLICK)
	{
		fract->julia.block = fract->julia.block == 1 ? 0 : 1;
		return (0);
	}
	else
		return (-1);
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_clear_window(fract->mlx, fract->win);
	ft_julia_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}

int				ft_julia_mouse_position(int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *)param;
	if (x < 0 || y < 0 || x >= fract->x_sizewin  || y >= fract->y_sizewin ||
		fract->julia.block == 1)
		return (-1);
	fract->julia.c_i = (double)x / 10000;
	fract->julia.c_r = (double)y / 1000;
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_clear_window(fract->mlx, fract->win);
	ft_julia_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_and_mouse_events.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:39:57 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 16:56:01 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_dezoom(int x, int y, t_type *type)
{
	double		converted_i;
	double		converted_r;

	if (y > 0)
	{
		converted_r = (x / type->zoom) + type->x_one;
		converted_i = (y / type->zoom) + type->y_one;
		type->zoom /= 1.1;
		type->iter_max -= 1;
		type->x_one = converted_r - (x / type->zoom);
		type->y_one = converted_i - (y / type->zoom);
	}
}

void			ft_zoom(int x, int y, t_type *type)
{
	double		converted_i;
	double		converted_r;

	if (y > 0)
	{
		converted_r = (x / type->zoom) + type->x_one;
		converted_i = (y / type->zoom) + type->y_one;
		type->zoom *= 1.1;
		type->iter_max += (type->iter_max > 90) ? 2 : 1;
		type->x_one = converted_r - (x / type->zoom);
		type->y_one = converted_i - (y / type->zoom);
	}
}

int				ft_mouse_button(int button, int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *)param;
	if (button == ZOOMPLUS)
		ft_zoom(x, y, &(fract->type));
	else if (button == ZOOMMINUS)
	{
		if (fract->type.zoom > 100)
			ft_dezoom(x, y, &(fract->type));
	}
	else if (button == RIGHTCLICK)
	{
		fract->type.block = fract->type.block == 1 ? 0 : 1;
		return (0);
	}
	else
		return (-1);
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_clear_window(fract->mlx, fract->win);
	ft_create_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}

int				ft_julia_mouse_position(int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *)param;
	if (x < 0 || y < 0 || x >= fract->x_sizewin || y >= fract->y_sizewin ||
		fract->type.block == 1)
		return (-1);
	fract->type.c_i = (double)x / 10000;
	fract->type.c_r = (double)y / 1000;
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_clear_window(fract->mlx, fract->win);
	ft_create_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}

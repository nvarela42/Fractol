/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:40:11 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/27 18:26:28 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_resetkey(t_fract *tmp)
{
	if (tmp->is_jul == 1)
	{
		tmp->x_sizewin = 400;
		tmp->y_sizewin = 400;
		tmp->julia.x_one = -1.5;
		tmp->julia.x_two = 1.5;
		tmp->julia.y_one = -1.5;
		tmp->julia.y_two = 1.5;
		tmp->julia.zoom = 100;
		tmp->julia.iter_max = 150;
		tmp->julia.c_r = 0.285;
		tmp->julia.c_i = 0.01;
		tmp->julia.block = 0;
	}
	else if (tmp->is_mand == 1)
	{
		tmp->x_sizewin = 400;
		tmp->y_sizewin = 400;
		tmp->mand.x_one = -2.1;
		tmp->mand.x_two = 0.6;
		tmp->mand.y_one = -1.2;
		tmp->mand.y_two = 1.2;
		tmp->mand.zoom = 100;
		tmp->mand.block = 0;
	}
}

static void		ft_movekey(int key, t_fract *tmp)
{
	if (key == 124)
	{
		if (tmp->is_jul == 1)
			tmp->julia.x_one *= 1.01;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.x_one *= 1.01;
	}
	else if (key == 123)
	{
		if (tmp->is_jul == 1)
			tmp->julia.x_one *= 0.99;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.x_one *= 0.99;
	}
	else if (key == 125)
	{
		if (tmp->is_jul == 1)
			tmp->julia.y_one *= 1.01;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.y_one *= 1.01;
	}
	else if (key == 126)
	{
		if (tmp->is_jul == 1)
			tmp->julia.y_one *= 0.99;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.y_one *= 0.99;
	}
}

static void		ft_zoomkey(int key, t_fract *tmp)
{
	if (key == KEYPLUS)
	{
		if (tmp->is_jul == 1)
			ft_julia_zoom(0, 0, &(tmp->julia));
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			ft_mandel_zoom(0, 0, &(tmp->mand));
	}
	else if (key == KEYMINUS)
	{
		if (tmp->is_jul == 1)
			ft_julia_dezoom(0, 0, &(tmp->julia));
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			ft_mandel_dezoom(0, 0, &(tmp->mand));
	}
}

int				quit_cross(t_fract *fract)
{
	(void)fract;
	exit(EXIT_SUCCESS);
	return (0);
}

int				ft_key_fonction(int key, void *param)
{
	t_fract *tmp;

	tmp = param;
	if (key == ESCAPEKEY)
		exit(EXIT_SUCCESS);
	if (key == KEYPLUS || key == KEYMINUS)
		ft_zoomkey(key, tmp);
	else if (key == 123 || key == 124 || key == 126 || key == 125)
		ft_movekey(key, tmp);
	else if (key == 15)
		ft_resetkey(tmp);
	mlx_destroy_image(tmp->mlx, tmp->image);
	mlx_clear_window(tmp->mlx, tmp->win);
	if (tmp->is_jul == 1)
		ft_julia_image(tmp);
	else if (tmp->is_mand == 1 || tmp->is_burn == 1)
		ft_mandel_image(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->image, 0, 0);
	return (0);
}

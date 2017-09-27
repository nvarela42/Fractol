/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:43:46 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/27 20:17:31 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_color_type(int key, t_fract *tmp)
{
	if (key == COLTYPE_ONE)
		tmp->color_type = COLTYPE_ONE;
	else if (key == COLTYPE_TWO)
		tmp->color_type = COLTYPE_TWO;
	else if (key == BASIC_COLTYPE)
		tmp->color_type = BASIC_COLTYPE;
}

void			ft_resetkey(t_fract *tmp)
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
		tmp->color_type = 0;
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
		tmp->color_type = 0;
	}
}

void			ft_movekey(int key, t_fract *tmp)
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

void			ft_zoomkey(int key, t_fract *tmp)
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

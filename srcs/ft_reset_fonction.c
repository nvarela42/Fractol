/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fonction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:33:42 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 17:35:56 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_reset_julia(t_fract *tmp)
{
	tmp->type.x_one = -1.8;
	tmp->type.x_two = 1.5;
	tmp->type.y_one = -1.8;
	tmp->type.y_two = 1.5;
	tmp->type.zoom = 100;
	tmp->type.iter_max = 50;
	tmp->type.c_r = 0.285;
	tmp->type.c_i = 0.01;
	tmp->type.block = 0;
	tmp->color_type = 0;
}

void			ft_reset_mandel(t_fract *tmp)
{
	tmp->type.x_one = -2.3;
	tmp->type.x_two = 0.6;
	tmp->type.y_one = -1.8;
	tmp->type.y_two = 1.2;
	tmp->type.zoom = 100;
	tmp->type.block = 0;
	tmp->color_type = 0;
	tmp->type.iter_max = 30;
}

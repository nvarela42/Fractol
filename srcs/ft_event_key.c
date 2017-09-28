/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:43:46 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 15:50:54 by nvarela          ###   ########.fr       */
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
		ft_reset_julia(tmp);
	else if (tmp->is_mand == 1 || tmp->is_burn == 1)
		ft_reset_mandel(tmp);
}

void			ft_movekey(int key, t_fract *tmp)
{
	if (key == 124)
		tmp->type.x_one *= 1.01;
	else if (key == 123)
		tmp->type.x_one *= 0.99;
	else if (key == 125)
		tmp->type.y_one *= 1.01;
	else if (key == 126)
		tmp->type.y_one *= 0.99;
}

void			ft_zoomkey(int key, t_fract *tmp)
{
	if (key == KEYPLUS)
		ft_zoom(0, 0, &tmp->type);
	else if (key == KEYMINUS)
		ft_dezoom(0, 0, &tmp->type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:28:56 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 13:35:27 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_create_image(t_fract *fract)
{
	fract->type.x_image = (fract->type.x_two - fract->type.x_one)
		* fract->type.zoom;
	fract->type.y_image = (fract->type.y_two - fract->type.y_one)
		* fract->type.zoom;
	fract->image = mlx_new_image(fract->mlx, fract->x_sizewin,
		fract->y_sizewin);
	fract->imgchar = mlx_get_data_addr(fract->image, &(fract->mlximgbpp),
	&(fract->mlximgsize), &(fract->mlximgendian));
	if (fract->is_jul == 1)
		ft_julia_search_z_point(fract, &(fract->type));
	else if (fract->is_mand == 1 || fract->is_burn == 1)
		ft_mand_search_z_point(fract, &(fract->type));
}

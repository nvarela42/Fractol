/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:40:11 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/14 19:28:34 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_movekey(int key, t_fract *tmp)
{
	if (key == 123)
	{
		if (tmp->is_jul == 1)
			tmp->julia.x_one *= 1.01;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.x_one *= 1.01;
	}
	else if (key == 124)
	{
		if (tmp->is_jul == 1)
			tmp->julia.x_one *= 0.99;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.x_one *= 0.99;
	}
	else if (key == 126)
	{
		if (tmp->is_jul == 1)
			tmp->julia.y_one *= 1.01;
		else if (tmp->is_mand == 1 || tmp->is_burn == 1)
			tmp->mand.y_one *= 1.01;
	}
	else if (key == 125)
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
	printf("key = %d\n", key);
	if (key == ESCAPEKEY)
		exit(EXIT_SUCCESS);
	if (key == KEYPLUS || key == KEYMINUS)
		ft_zoomkey(key, tmp);
	else if (key == 123 || key == 124 || key == 126 || key == 125)
		ft_movekey(key, tmp);
	mlx_destroy_image(tmp->mlx, tmp->image);
	mlx_clear_window(tmp->mlx, tmp->win);
	ft_julia_image(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->image, 0, 0);
	return (0);
}

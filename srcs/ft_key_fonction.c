/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:40:11 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 15:39:07 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_clear_image_and_win(t_fract *tmp)
{
	mlx_destroy_image(tmp->mlx, tmp->image);
	mlx_clear_window(tmp->mlx, tmp->win);
	ft_create_image(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->image, 0, 0);
	return (0);
}

int				quit_cross(t_fract *fract)
{
	(void)fract;
	// ft_free_struct(&fract);
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
	else if (key == LEFTKEY || key == RIGHTKEY || key == UPKEY ||
		key == DOWNKEY)
		ft_movekey(key, tmp);
	else if (key == RESETKEY)
		ft_resetkey(tmp);
	else if (key == COLTYPE_ONE || key == COLTYPE_TWO || key == BASIC_COLTYPE)
		ft_color_type(key, tmp);
	ft_clear_image_and_win(tmp);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:40:11 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/12 19:05:53 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				quit_cross(t_fract *fract)
{
	(void)fract;
	exit(EXIT_SUCCESS);
	return (0);
}

int				ft_key_fonction(int keycode, void *param)
{
	// t_fract *tmp;

	// tmp = param;
	printf("code = %d\n", keycode);
	if (keycode == ESCAPEKEY)
		exit(EXIT_SUCCESS);
/*	if (keycode == KEYPLUS)
	{
		if (&(tmp->julia) != NULL)
			ft_julia_zoom(x, y, &(tmp->julia));
		else if (&(tmp->mand) != NULL)
			ft_mandel_zoom(x, y, &(tmp->mand));
	}*/

	(void)param;
	return (0);
}

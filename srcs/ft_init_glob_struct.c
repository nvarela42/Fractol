/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_glob_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:04:38 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/14 20:09:38 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_fill_struct(t_fract *fract)
{
	fract->x_sizewin = 0;
	fract->y_sizewin = 0;
	fract->mlx = NULL;
	fract->win = NULL;
	fract->image = NULL;
	fract->imgchar = NULL;
	fract->is_burn = 0;
	fract->is_jul = 0;
	fract->is_mand = 0;
	fract->col = ft_lstco();
}

t_fract				*ft_init_glob_struct(void)
{
	static t_fract	*fract = NULL;
	static int		check = 0;

	if (fract == NULL && check == 0)
	{
		if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
			return (NULL);
		check = 1;
		ft_fill_struct(fract);
	}
	return (fract);
}

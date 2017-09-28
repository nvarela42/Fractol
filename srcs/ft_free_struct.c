/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:39:19 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 14:51:52 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_free_struct(t_fract **fract)
{
	ft_memdel((void **)&(*fract)->color_type);
	ft_memdel((void **)fract);
	*fract = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:15:41 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/27 20:00:44 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color			*ft_basic_color(t_color *col)
{
	col[0] = (t_color){255, 102, 0};
	col[1] = (t_color){255, 204, 51};
	col[2] = (t_color){255, 255, 153};
	col[3] = (t_color){255, 0, 0};
	col[4] = (t_color){255, 204, 153};
	return (col);
}

t_color			*ft_col_type_one(t_color *col)
{
	col[0] = (t_color){0, 153, 255};
	col[1] = (t_color){0, 0, 204};
	col[2] = (t_color){153, 155, 51};
	col[3] = (t_color){0, 153, 153};
	col[4] = (t_color){102, 255, 0};
	return (col);
}

t_color			*ft_col_type_two(t_color *col)
{
	col[0] = (t_color){255, 0, 153};
	col[1] = (t_color){102, 51, 153};
	col[2] = (t_color){255, 102, 255};
	col[3] = (t_color){255, 204, 255};
	col[4] = (t_color){204, 102, 102};
	return (col);
}

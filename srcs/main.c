/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:05:54 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 18:18:43 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_start_fractol(t_fract *fract, char **av)
{
	ft_usage_on_console();
	if (ft_strcmp(av[1], "julia") == 0)
	{
		fract->is_jul = 1;
		ft_julia_fract(fract);
	}
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		fract->is_mand = 1;
		ft_mandel_fract(fract);
	}
	else if (ft_strcmp(av[1], "burningship") == 0)
	{
		fract->is_burn = 1;
		ft_mandel_fract(fract);
	}
	return ;
}

int				main(int argc, char **argv)
{
	if (ft_parser(argc, argv) == -1)
		return (EXIT_FAILURE);
	ft_start_fractol(ft_init_glob_struct(), argv);
	return (0);
}

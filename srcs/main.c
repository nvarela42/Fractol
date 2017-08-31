/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:05:54 by nvarela           #+#    #+#             */
/*   Updated: 2017/08/31 18:05:01 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void  ft_start_fractol(t_fract *fract, char **av)
{
	if (ft_strcmp(av[1], "julia") == 0)
		ft_julia_fract(fract);
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		fract->burn = 0;
		ft_mandel_fract(fract);
	}
	else if (ft_strcmp(av[1], "burningship") == 0)
	{
		fract->burn = 1;
		ft_mandel_fract(fract);
	}
	return ;
}


int         main(int argc, char **argv)
{
	if (ft_parser(argc, argv) == -1)
		return (EXIT_FAILURE);
	ft_start_fractol(ft_init_glob_struct(), argv);
	return (0);
}

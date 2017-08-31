/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:05:07 by nvarela           #+#    #+#             */
/*   Updated: 2017/08/29 18:05:09 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			ft_parse_arg(char **av)
{
	if (ft_strcmp(av[1], "julia") == 0)
		return (0);
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(av[1], "burningship") == 0)
		return (0);
	return(-1);
}

static void			ft_usage(void)
{
	ft_putstr(BOLD);
	ft_putstr(UNDERLINE);
	ft_putstr("Usage:");
	ft_putstr(DEFAULT_COLOR);
	ft_putendl(" ./fractol FRACTAL_NAME \n");
	ft_putstr(PURPLE);
	ft_putstr(UNDERLINE);
	ft_putstr("FRACTAL_NAME");
	ft_putstr(DEFAULT_COLOR);
	ft_putstr(PURPLE);
	ft_putendl(" Can be one of this :");
	ft_putendl("            - mandelbrot");
	ft_putendl("            - julia");
	ft_putendl("            - burningship");
}

int					ft_error(char *s)
{
	ft_putstr(RED);
	ft_putendl(s);
	ft_usage();
	return (-1);
}

int					ft_parser(int ac, char **av)
{
	t_fract			*fract;

	fract = NULL;
	if (ac != 2)
		return (ft_error("Wrong number of argument."));
	if ((fract = ft_init_glob_struct()) == NULL)
		return (-1);
	if (ft_parse_arg(av) == -1)
		return (ft_error("Wrong fractal name."));
	return (0);
}

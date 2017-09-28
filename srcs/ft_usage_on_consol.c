/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_on_consol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:42:11 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/28 18:55:16 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_usage_reset(void)
{
	ft_putendl("  "UNDERLINE RED "RESET"DEFAULT_COLOR);
	ft_putstr(YELLOW"  reset map: "DEFAULT_COLOR);
	ft_putendl(WHITE"'r' key (touch 'r').");
}

static void		ft_usage_color(void)
{
	ft_putendl("  "UNDERLINE RED"COLOR"DEFAULT_COLOR);
	ft_putchar('\n');
	ft_putstr(YELLOW"  basic color: " DEFAULT_COLOR);
	ft_putendl(WHITE"num pad '0' (pave num '0').");
	ft_putstr(YELLOW"  set color one: "DEFAULT_COLOR);
	ft_putendl(WHITE"num pad '1' (pave num '1').");
	ft_putstr(YELLOW"  set color two: "DEFAULT_COLOR);
	ft_putendl(WHITE"num pad '2' (pave num '2').");
}

static void		ft_usage_mouse_key(void)
{
	ft_putendl("  "UNDERLINE RED"ZOOM AND MOUSE" DEFAULT_COLOR);
	ft_putendl("\n");
	ft_putstr(YELLOW"  change constant of julia: ");
	ft_putendl(WHITE"move the mouse on window (deplacez la souris sur la"
	" fenetre).");
	ft_putstr(YELLOW"  lock constant of julia: ");
	ft_putendl(WHITE"right mouse button (click droit de la souris).");
	ft_putstr(YELLOW"  zoom ++: ");
	ft_putendl(WHITE"mouse wheel (molette de la souris).");
	ft_putstr(YELLOW"  zoom --: ");
	ft_putendl(WHITE"mouse wheel (molette de la souris).");
}

static void		ft_usage_move_key(void)
{
	ft_putendl("  "UNDERLINE RED"MOVEMENT"DEFAULT_COLOR);
	ft_putendl("\n");
	ft_putstr(YELLOW"  move right: ");
	ft_putendl(WHITE"right arrow (fleche droite).");
	ft_putstr(YELLOW"  move left: "DEFAULT_COLOR);
	ft_putendl(WHITE"left arrow (fleche gauche).");
	ft_putstr(YELLOW"  move up: "DEFAULT_COLOR);
	ft_putendl(WHITE"up arrow (fleche du haut).");
	ft_putstr(YELLOW"  move dawn: "DEFAULT_COLOR);
	ft_putendl(WHITE"dawn arrow (fleche du bas).");
}

void			ft_usage_on_console(void)
{
	ft_putendl("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_putendl(PURPLE"     __________________________________     ");
	ft_putendl("\n");
	ft_putendl(PURPLE "             M  O  T  I  O  N     "DEFAULT_COLOR);
	ft_putendl("\n");
	ft_usage_move_key();
	ft_putendl("\n\n");
	ft_usage_mouse_key();
	ft_putendl("\n\n");
	ft_usage_color();
	ft_putendl("\n\n");
	ft_usage_reset();
	ft_putendl("\n");
	ft_putendl(PURPLE"     __________________________________     ");
	ft_putendl("\n\n\n\n\n\n\n");
}

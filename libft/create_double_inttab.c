/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_double_inttab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:18:14 by nvarela           #+#    #+#             */
/*   Updated: 2017/03/08 04:20:41 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**create_double_inttab(int **tab, int len_big_tab, int len_little_tab)
{
	int	i;
	int	y;

	tab = (int **)malloc(sizeof(int *) * len_big_tab);
	i = 0;
	y = 0;
	while (i < len_big_tab)
	{
		tab[i] = (int *)malloc(sizeof(int) * len_little_tab);
		tab[i][len_little_tab] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

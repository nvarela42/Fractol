/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_inttab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:58:50 by nvarela           #+#    #+#             */
/*   Updated: 2017/03/14 06:48:38 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_inttab(int **tab)
{
	int i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free((void*)tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
	free(tab);
}

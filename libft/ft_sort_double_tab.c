/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_double_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:36:45 by nvarela           #+#    #+#             */
/*   Updated: 2017/08/28 16:36:50 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_sort_rev(char **tab)
{
	char		*tmp1;
	char		*tmp2;
	int			i;
	int			j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp1 = tab[i];
				tmp2 = tab[j];
				tab[i] = tmp2;
				tab[j] = tmp1;
			}
			else
				j++;
		}
		i++;
	}
	return (tab);
}

static char		**ft_sort_by_alpha(char **tab)
{
	char		*tmp1;
	char		*tmp2;
	int			i;
	int			j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) < 0)
			{
				tmp1 = tab[i];
				tmp2 = tab[j];
				tab[i] = tmp2;
				tab[j] = tmp1;
			}
			else
				j++;
		}
		i++;
	}
	return (tab);
}

char			**ft_sort_double_tab(char **tab, int type)
{
	if (type == 1)
		tab = ft_sort_by_alpha(tab);
	if (type == 2)
		tab = ft_sort_rev(tab);
	return (tab);
}

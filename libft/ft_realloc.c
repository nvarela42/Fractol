/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 02:32:09 by nvarela           #+#    #+#             */
/*   Updated: 2017/03/17 01:42:36 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_new_extension(char **tab)
{
	char	**ret_tab;
	int		i;
	int		j;

	j = 0;
	if (tab != NULL)
	{
		while (tab[j] != NULL)
			j++;
	}
	j += 2;
	if ((ret_tab = (char **)malloc(sizeof(char *) * j)) == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		ret_tab[i] = NULL;
		i++;
	}
	return (ret_tab);
}

char			**ft_realloc(char **tab, char *str)
{
	char	**ret_tab;
	int		i;

	if ((ret_tab = ft_new_extension(tab)) == NULL)
		return (NULL);
	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			ret_tab[i] = ft_strdup(tab[i]);
			i++;
		}
	}
	ret_tab[i] = ft_strdup(str);
	free_double_chartab(tab);
	return (ret_tab);
}

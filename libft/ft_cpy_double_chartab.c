/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_double_chartab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:58:06 by nvarela           #+#    #+#             */
/*   Updated: 2017/08/29 19:29:38 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_cpy_double_chartab(char **tab, int base)
{
	char		**newtab;
	int			len;
	int			i;

	i = base;
	len = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	if (!(newtab = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	i = 0;
	while (tab[base] != '\0')
	{
		newtab[i] = ft_strdup(tab[base]);
		base++;
		i++;
	}
	newtab[i] = NULL;
	return (newtab);
}

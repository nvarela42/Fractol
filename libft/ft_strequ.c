/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:00:20 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/23 18:38:34 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;
	size_t y;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1);
	y = ft_strlen(s2);
	if (i != y)
		return (0);
	while (i-- > 0)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:49:38 by nvarela           #+#    #+#             */
/*   Updated: 2016/12/01 15:43:32 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strnequ(const char *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = n;
	while (i-- > 0)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

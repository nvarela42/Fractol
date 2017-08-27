/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:20:41 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/22 17:20:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*c1;
	const char	*c2;

	if (n)
	{
		c1 = (char *)s1;
		c2 = (char *)s2;
		while (n-- > 0)
		{
			*c1++ = *c2++;
			if (*(c1 - 1) == c)
				return (c1);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:19:04 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/22 17:19:13 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;

	s_tmp = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*s_tmp == (unsigned char)c)
			return ((void *)s_tmp);
		s_tmp++;
	}
	return (0);
}

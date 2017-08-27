/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:28:42 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/22 17:29:00 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	src_size;
	size_t	dest_size;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (dest_size > size)
		return (size + src_size);
	while ((i + dest_size) < (size - 1) && src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}

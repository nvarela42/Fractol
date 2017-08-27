/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:08:17 by nvarela           #+#    #+#             */
/*   Updated: 2016/12/01 17:35:42 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	alloc = (char *)malloc(sizeof(char) * size);
	if (alloc == 0)
		return (NULL);
	while (i < size)
	{
		alloc[i] = 0;
		i++;
	}
	return (alloc);
}

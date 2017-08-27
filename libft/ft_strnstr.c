/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:41:40 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/28 15:59:07 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*c1;
	char	*c2;
	size_t	i;
	size_t	j;

	c1 = (char *)s1;
	c2 = (char *)s2;
	if (*c2 == '\0')
		return (c1);
	i = 0;
	j = ft_strlen(c2);
	while (c1[i] && (i < len) && j <= (len - i))
	{
		if (ft_strncmp(c1 + i, c2, j) == 0)
			return (c1 + i);
		i++;
	}
	return (NULL);
}

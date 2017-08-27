/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:45:15 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/25 20:29:37 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	length;
	char	*c1;
	char	*c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	if (*c2 == '\0')
		return (c1);
	length = ft_strlen(c2);
	while (*c1)
	{
		if (ft_strncmp(c1, c2, length) == 0)
			return (c1);
		c1++;
	}
	return (NULL);
}

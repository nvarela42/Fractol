/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:13:29 by nvarela           #+#    #+#             */
/*   Updated: 2017/02/13 21:13:49 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t size)
{
	char	*freshstr;
	size_t	len;
	size_t	i;
	size_t	j;

	len = (ft_strlen(s1) + (size + 1));
	if (!(freshstr = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		freshstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size)
		freshstr[i++] = s2[j++];
	freshstr[i] = '\0';
	return (freshstr);
}

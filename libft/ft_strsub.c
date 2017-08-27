/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:16:35 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/24 16:30:37 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*freshstr;

	if (s == 0)
		return (NULL);
	freshstr = (char *)malloc(sizeof(char) * (len + 1));
	if (freshstr == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		freshstr[i++] = s[start++];
	}
	freshstr[i] = '\0';
	return (freshstr);
}

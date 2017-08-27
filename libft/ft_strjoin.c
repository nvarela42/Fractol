/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:52:21 by nvarela           #+#    #+#             */
/*   Updated: 2017/05/11 11:55:42 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_n)
{
	char	*freshstr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	freshstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!freshstr)
		return (NULL);
	ft_strcpy(freshstr, s1);
	ft_strcat(freshstr, s2);
	if (free_n == 1)
		free((char *)s1);
	if (free_n == 2)
		free((char *)s2);
	if (free_n == 0)
	{
		free((char *)s1);
		free((char *)s2);
	}
	return (freshstr);
}

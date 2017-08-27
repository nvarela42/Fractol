/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:28:01 by nvarela           #+#    #+#             */
/*   Updated: 2017/05/11 11:29:33 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;
	int		lenght;

	lenght = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (lenght + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

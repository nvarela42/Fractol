/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:04:51 by nvarela           #+#    #+#             */
/*   Updated: 2017/07/06 17:32:12 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(char *str)
{
	int			i;
	int			len;
	char		tmp;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i < (len / 2))
	{
		tmp = str[i];
		str[len] = tmp;
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

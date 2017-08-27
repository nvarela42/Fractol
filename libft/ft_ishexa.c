/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:09:05 by nvarela           #+#    #+#             */
/*   Updated: 2017/03/31 12:24:44 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char *str)
{
	int			i;

	i = 2;
	if (ft_strlen(str) < 3 || (str[0] == '0' && str[1] != 'x'))
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'a' ||
			str[i] == 'A' || str[i] == 'a' || str[i] == 'B' || str[i] == 'c' ||
			str[i] == 'C' || str[i] == 'd' || str[i] == 'D' || str[i] == 'e' ||
			str[i] == 'E' || str[i] == 'f' || str[i] == 'F')
			i++;
		else
			return (0);
	}
	return (1);
}

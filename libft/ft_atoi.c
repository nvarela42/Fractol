/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:10:22 by nvarela           #+#    #+#             */
/*   Updated: 2016/12/01 15:41:00 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	box;
	int	isneg;

	i = 0;
	isneg = 1;
	while (str[i] == '\r' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\f' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	box = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		box = (box * 10) + (str[i] - 48);
		i++;
	}
	return (isneg * box);
}

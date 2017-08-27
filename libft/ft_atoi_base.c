/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 06:11:00 by nvarela           #+#    #+#             */
/*   Updated: 2017/04/27 05:19:29 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_char_in_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int				ft_atoi_base(char *str, char *base)
{
	int		ret;
	int		i;
	int		mult;
	int		power;

	i = 0;
	ret = 0;
	mult = ft_strlen(base);
	power = ft_strlen(str) - 1;
	while (str[i])
	{
		if (power != 0)
			ret += find_char_in_base(str[i], base) * ft_power(mult, power);
		else
			ret += find_char_in_base(str[i], base);
		i++;
		power--;
	}
	return (ret);
}

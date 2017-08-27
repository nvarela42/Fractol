/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:20:52 by nvarela           #+#    #+#             */
/*   Updated: 2016/12/01 15:14:34 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	char	*tab;

	i = ft_counter_number(n);
	if (!(tab = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		tab[0] = '-';
	else
		n = n * (-1);
	tab[i] = '\0';
	while (i >= 1 && tab[i - 1] != '-')
	{
		tab[--i] = -(n % 10) + 48;
		n /= 10;
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:46:28 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/30 13:53:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int result;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		result = nb * ft_power(nb, power - 1);
	return (result);
}

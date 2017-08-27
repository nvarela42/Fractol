/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:32:06 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/25 19:26:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int stock;

	stock = n;
	if (stock < 0)
	{
		ft_putchar('-');
		stock = stock * (-1);
	}
	if (stock >= 10)
		ft_putnbr(stock / 10);
	ft_putchar((stock % 10) + '0');
}

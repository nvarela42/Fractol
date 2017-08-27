/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:22:08 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/25 19:30:01 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int stock;

	stock = n;
	if (stock < 0)
	{
		ft_putchar_fd('-', fd);
		stock = stock * (-1);
	}
	if (stock >= 10)
		ft_putnbr_fd(stock / 10, fd);
	ft_putchar_fd((stock % 10) + '0', fd);
}

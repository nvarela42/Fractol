/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_of_caract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:29:43 by nvarela           #+#    #+#             */
/*   Updated: 2017/06/23 10:54:16 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_nbr_of_caract(char *str, char c)
{
	int				i;
	int				counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

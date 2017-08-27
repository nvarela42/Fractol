/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_caract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:18:29 by nvarela           #+#    #+#             */
/*   Updated: 2017/06/22 15:26:40 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_search_final_caract(char *str, char c)
{
	int				i;
	int				counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (str[i - 1] == c)
		counter = 1;
	return (counter);
}

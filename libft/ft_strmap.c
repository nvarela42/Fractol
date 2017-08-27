/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:40:25 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/23 17:33:53 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*freshstr;

	if (s == 0)
		return (NULL);
	i = 0;
	freshstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (freshstr == 0)
		return (NULL);
	while (s[i])
	{
		freshstr[i] = f(s[i]);
		i++;
	}
	freshstr[i] = '\0';
	return (freshstr);
}

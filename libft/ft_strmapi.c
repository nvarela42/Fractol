/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:27:49 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/23 18:39:04 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*freshstr;

	i = 0;
	if (s == 0)
		return (NULL);
	freshstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (freshstr == 0)
		return (NULL);
	while (s[i])
	{
		freshstr[i] = f(i, s[i]);
		i++;
	}
	freshstr[i] = '\0';
	return (freshstr);
}

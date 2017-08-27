/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:26:14 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/24 16:32:36 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*freshstr;

	if (s == 0)
		return (ft_strnew(1));
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	j--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j > i))
		j--;
	if (j == 0)
		return (ft_strnew(1));
	len = j - i;
	freshstr = ft_strsub(s, i, len + 1);
	return (freshstr);
}

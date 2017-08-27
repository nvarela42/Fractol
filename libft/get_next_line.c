/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:48:17 by nvarela           #+#    #+#             */
/*   Updated: 2017/05/11 11:47:13 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*str_mvleft(char *str, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		str[i - 1] = str[i];
		i++;
	}
	return (str);
}

static char		*str_rmnullchar(char *str, int len)
{
	int		i;

	i = 0;
	while (len)
	{
		if (str[i] == 0)
			str_mvleft(&str[i], len);
		else
			i++;
		len--;
	}
	str[i] = 0;
	return (str);
}

static int		check_buffer(char *buf, char **line)
{
	char	*new;
	char	*p;

	if ((p = ft_strchr(buf, '\n')) != NULL)
	{
		if (!(new = ft_strndup(buf, p - buf)))
			return (-1);
		ft_strcpy(buf, ++p);
	}
	else
	{
		if (!(new = ft_strdup(buf)))
			return (-1);
		buf[0] = 0;
	}
	if (!(*line = ft_strjoin(*line, new, 3)))
		return (-1);
	free(new);
	if (p)
		return (1);
	return (0);
}

static int		del_and_error(char **line)
{
	if (*line)
		ft_strdel(line);
	return (-1);
}

int				get_next_line(int const fd, char **line)
{
	static char		buffer[BUFF_SIZE + 1] = {0};
	int				ret;
	int				buffchck;

	if (!(*line = ft_strnew(0))
			|| (buffchck = check_buffer(buffer, line)) < 0)
		return (del_and_error(line));
	if (buffchck)
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = 0;
		str_rmnullchar(buffer, ret);
		if ((buffchck = check_buffer(buffer, line)) == 1)
			return (1);
		else if (buffchck == -1)
			return (-1);
	}
	if (ret == 0 && ft_strlen(*line))
		return (1);
	ft_strdel(line);
	return (ret);
}

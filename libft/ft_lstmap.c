/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:10:30 by nvarela           #+#    #+#             */
/*   Updated: 2016/11/29 19:02:05 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*savelst;
	t_list	*copylst;
	t_list	*tempcopy;

	copylst = NULL;
	temp = lst;
	savelst = f(lst);
	copylst = ft_lstnew(savelst->content, savelst->content_size);
	tempcopy = copylst;
	temp = lst->next;
	lst = temp;
	while (temp)
	{
		temp = temp->next;
		savelst = f(lst);
		if (!(savelst))
			free(savelst);
		copylst->next = ft_lstnew(savelst->content, savelst->content_size);
		if (!(copylst->next))
			return (NULL);
		copylst = copylst->next;
		lst = temp;
	}
	return (tempcopy);
}

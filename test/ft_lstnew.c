/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 11:50:12 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/08 21:05:35 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if ((newlist = malloc(sizeof(*newlist))) == NULL)
		return (NULL);
	newlist->next = NULL;
	if (content == NULL)
	{
		newlist->next = NULL;
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->next = NULL;
		if (!(newlist->content = ft_memalloc(content_size)))
			return (NULL);
		newlist->content = ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	return (newlist);
}

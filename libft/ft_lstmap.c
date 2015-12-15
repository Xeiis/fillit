/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:21:57 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/07 15:37:10 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	if ((result = ft_lstnew(tmp2->content, tmp2->content_size)))
	{
		tmp = result;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			if (!(tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (result);
}

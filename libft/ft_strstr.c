/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:10:09 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/09 18:15:05 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*s1 && *s2)
	{
		i = 0;
		while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i))
		{
			++i;
			if (!*(s2 + i))
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}

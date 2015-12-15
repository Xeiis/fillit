/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:07:29 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/09 18:12:48 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		else if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}

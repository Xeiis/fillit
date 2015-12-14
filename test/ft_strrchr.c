/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:05:53 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/09 18:12:35 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return (NULL);
}

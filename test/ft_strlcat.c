/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:24:58 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/06 09:30:30 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	if (size < i)
		total = size + ft_strlen(s2);
	else
		total = ft_strlen(s1) + ft_strlen(s2);
	while (s2[j] != '\0' && i + 1 < size)
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (total);
}

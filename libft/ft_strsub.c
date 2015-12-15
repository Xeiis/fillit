/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 23:18:20 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/08 20:48:00 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	int		j;

	dest = NULL;
	i = 0;
	j = 0;
	if ((long)len >= 0)
	{
		if ((dest = (char *)malloc((len + 1) * sizeof(*dest))) == NULL)
			return (NULL);
		while (s[i] != '\0' && len)
		{
			if (i >= start)
			{
				dest[j] = s[i];
				j++;
				len--;
			}
			i++;
		}
		dest[j] = '\0';
	}
	return (dest);
}

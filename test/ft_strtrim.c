/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 23:29:31 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/09 16:07:50 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_initialisation(int *len, int *i, int *blank, const char *s)
{
	*i = 0;
	*blank = 0;
	while ((ft_isblank(s[*i]) || s[*i] == '\n') && s[*i] != '\0')
	{
		*i = *i + 1;
		*blank = *blank + 1;
	}
	*len = ft_strlen(s);
	*len = *len - 1;
	while ((ft_isblank(s[*len]) || s[*len] == '\n') && *len > 1)
	{
		*blank = *blank + 1;
		*len = *len - 1;
	}
	*i = *i - 1;
	*len = *len + 1;
}

char			*ft_strtrim(char const *s)
{
	char	*dest;
	int		i;
	int		blank;
	int		j;
	int		len;

	j = 0;
	ft_initialisation(&len, &i, &blank, s);
	if ((int)(ft_strlen(s) - blank) < 0)
	{
		if ((dest = (char *)malloc(1 * sizeof(*dest))) == NULL)
			return (NULL);
	}
	else
	{
		if ((dest = (char *)malloc(((ft_strlen(s) + 1) - blank) *
						sizeof(char)))
				== NULL)
			return (NULL);
	}
	while (s[++i] != '\0' && i < len)
		dest[j++] = s[i];
	dest[j] = '\0';
	return (dest);
}

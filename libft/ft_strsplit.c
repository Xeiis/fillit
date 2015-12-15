/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:37:21 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/09 15:27:29 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_howmuchwords(char *s, char c)
{
	int		mot;
	int		i;

	i = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			mot++;
			i++;
		}
	}
	return (mot);
}

static int	ft_len(char *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

static char	*ft_writeword(char *s, char *dest, char c, int start)
{
	int		i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_write_all_word(char **dest, char *s, char c, int start)
{
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (s[i] != '\0')
	{
		len = ft_len(s, c, start);
		if ((dest[j] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		dest[j] = ft_writeword(s, dest[j], c, start);
		j++;
		i += ft_len(s, c, start);
		while (s[i] == c && s[i])
			i++;
		start = i;
	}
	dest[j] = 0;
	return (dest);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		mot;
	int		i;

	i = 0;
	mot = ft_howmuchwords((char *)s, c);
	if ((dest = (char **)malloc(sizeof(char *) * (mot + 1))) == NULL)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	dest = ft_write_all_word(dest, (char *)s, c, i);
	return (dest);
}

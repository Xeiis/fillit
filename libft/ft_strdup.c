/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:40:41 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/08 20:40:28 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dest;

	if ((dest = (char *)malloc((sizeof(char) * (ft_strlen(s) + 1)))) == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s);
	return (dest);
}

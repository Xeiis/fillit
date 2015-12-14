/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:17:31 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/06 09:21:23 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

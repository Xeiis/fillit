/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:29:43 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/09 18:14:23 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		neg;

	result = 0;
	i = 0;
	neg = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v') && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

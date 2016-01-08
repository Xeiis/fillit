/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:44:37 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/08 19:16:26 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

void				ft_affichage_solution(char *map, int min_sqr)
{
	int				x;
	int				y;
	int				i;

	y = -1;
	i = 0;
	while (++y < min_sqr)
	{
		x = -1;
		while (++x < min_sqr)
		{
			if (ft_isupper(map[i]))
				ft_putchar(map[i++]);
			else
			{
				ft_putchar('.');
				i++;
			}
		}
		ft_putchar('\n');
	}
}

double				ft_sqrt(double n, double i)
{
	if (((n * 10000) - (i * i)) <= 0)
		return (i / 100);
	else
		return (ft_sqrt(n, i + 1));
}

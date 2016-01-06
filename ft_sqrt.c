/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:44:37 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/06 11:57:28 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

void				ft_affichage_solution(char *map, int min_sqr)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (x < min_sqr)
	{
		if (ft_isupper(map[x + y]))
			ft_putchar(map[x + y]);
		else
			ft_putchar('.');
		if (y == min_sqr)
		{
			++x;
			ft_putchar('\n');
		}
		else
			++y;
	}
}

double				ft_sqrt(double n, double i)
{
	if (((n * 10000) - (i * i)) <= 0)
		return (i / 100);
	else
		return (ft_sqrt(n, i + 1));
}

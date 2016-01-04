/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:18:39 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/04 19:18:43 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

int					main(int argc, char **argv)
{
	t_tetrimino		*t;

	if (!(t = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (0);
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		t = ft_gettab(argv[1]);
		if (!t)
			write(1, "error\n", 6);
		else
		{
			ft_sort_tetri(t);
			ft_affichage(t);
			write(1, "ok\n", 3);
		}
	}
	return (0);
}

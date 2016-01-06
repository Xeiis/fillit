/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:37:58 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/06 15:11:03 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_is_back_line(int *y, int *x)
{
	if (*x != 4 && *y != 4)
		return (0);
	*y = *y + 1;
	*x = 0;
	return (1);
}

int					ft_isvalidchar(char c)
{
	if (c == '\n' || c == '#' || c == '.' || c == '\0')
		return (1);
	return (0);
}

void				ft_sort_tetri(t_tetrimino *tetrimino)
{
	int x;
	int y;
	int i;

	printf("test : %c\n", tetrimino->c);
	while (tetrimino->next != NULL)
	{
		x = tetrimino->c_pos[0].x;
		y = tetrimino->c_pos[0].y;
		i = -1;
		while (++i < 3)
		{
			if (tetrimino->c_pos[i + 1].x < x)
				x = tetrimino->c_pos[i + 1].x;
			if (tetrimino->c_pos[i + 1].y < y)
				y = tetrimino->c_pos[i + 1].y;
		}
		i = -1;
		while (++i < 4)
		{
			tetrimino->c_pos[i].x -= x;
			tetrimino->c_pos[i].y -= y;
		}
		tetrimino = tetrimino->next;
	}
}

int					ft_test_dlm(t_tetrimino tetrimino, int i)
{
	int x_d;
	int y_d;

	x_d = tetrimino.c_pos[i + 1].x - tetrimino.c_pos[i - 1].x;
	y_d = tetrimino.c_pos[i + 1].y - tetrimino.c_pos[i - 1].y;
	if ((x_d >= -1 && x_d <= 1 && y_d == 0) ||
		(y_d >= -1 && y_d <= 1 && x_d == 0))
		return (1);
	return (0);
}

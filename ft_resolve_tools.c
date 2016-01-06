/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 01:01:07 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/06 19:19:45 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				max_allx_tetri(t_tetrimino *tetrimino)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++y < 4)
	{
		if (max_x_tetri(tetrimino, y) > x)
			x = max_x_tetri(tetrimino, y);
	}
	return (x);
}

int				max_ally_tetri(t_tetrimino *tetrimino)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++x < 4)
		if (max_y_tetri(tetrimino, x) > y)
			y = max_y_tetri(tetrimino, x);
	return (y);
}

void			ft_init2(int *y, int *ok, int *x)
{
	*y = -1;
	*ok = 0;
	*x = 0;
}

int				ft_test_write(t_tetrimino *tetrimino,
		char *map, t_vector2 vector)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	while (y < vector.y && x < vector.x)
	{
		i = 0;
		while (!ft_isupper(map[tetrimino->c_pos[i].x + x +
				tetrimino->c_pos[i].y] + y))
			i++;
		if (i == 4)
			return (1);
		if (x == vector.x)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	return (0);
}

int				ft_write_tetri(t_tetrimino *t, char *map, int min_sqr, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < min_sqr && x < min_sqr)
	{
		i = -1;
		while (i < 4 && !ft_isupper((map[t->c_pos[i].x + x + t->c_pos[i].y + y])))
			++i;
		if (i == 4)
		{
			i = -1;
			while (++i < 4)
			{
				map[(t->c_pos[i].x) + x + t->c_pos[i].y * min_sqr + y * min_sqr] = t->c;
				printf("{B} map[%d * %d +  %d * %d + %d + %d] => '%c'\n", t->c_pos[i].x, min_sqr, x, min_sqr, t->c_pos[i].y, y, map[t->c_pos[i].x + x + t->c_pos[i].y + y]);
			}
		}
		if (x == min_sqr)
		{
			x = 0;
			++y;
		}
		else
			++x;
	}
	return (1);
}

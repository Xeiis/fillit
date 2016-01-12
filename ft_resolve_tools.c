/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 01:01:07 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/12 19:41:28 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				max_allx_tetri(t_tetrimino *tetrimino)
{
	int			y;
	int			x;

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
	int			y;
	int			x;

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

int				ft_write_tetri_vector(t_tetrimino *t, char *map,
		int min_sqr, int i)
{
	while (++i < 4 && !ft_isupper(map[t->c_pos[i].x + t->w_pos.x +
				t->c_pos[i].y * min_sqr + t->w_pos.y * min_sqr]))
	{
		if (t->c_pos[i].x + t->w_pos.x >= min_sqr)
			break ;
		if (t->c_pos[i].y + t->w_pos.y >= min_sqr)
			break ;
	}
	if (i == 4)
	{
		i = -1;
		while (++i < 4)
		{
			map[t->c_pos[i].x + t->w_pos.x + t->c_pos[i].y * min_sqr +
				t->w_pos.y * min_sqr] = t->c;
		}
		return (1);
	}
	if (max_x_tetri(t, t->w_pos.y) + max_x_line(map, t->w_pos.y, min_sqr) >
			min_sqr && max_y_tetri(t, t->w_pos.x) + max_y_line(map,
				t->w_pos.x, min_sqr) > min_sqr)
		return (0);
	return (0);
}

void			ft_suppr_tetri_vector(t_tetrimino *t, char *map, int min_sqr)
{
	int			i;

	i = -1;
	while (++i < 4)
		map[t->c_pos[i].x + t->w_pos.x + t->c_pos[i].y * min_sqr +
			t->w_pos.y * min_sqr] = '.';
}

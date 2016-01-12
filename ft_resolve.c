/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:51:45 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/12 19:42:16 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				max_y_line(char *map, int x, int min_sqr)
{
	int i;
	int y;

	y = -1;
	i = 0;
	while (map[x + i * min_sqr] != '\0')
	{
		if (ft_isupper(map[x + i]))
			if (i > y)
				y = i;
		++i;
	}
	return (y + 1);
}

int				max_x_tetri(t_tetrimino *tetrimino, int y)
{
	int i;
	int x;

	i = -1;
	x = -1;
	while (++i < 4)
	{
		if (tetrimino->c_pos[i].y == y)
			if (tetrimino->c_pos[i].x > x)
				x = tetrimino->c_pos[i].x;
	}
	return (x + 1);
}

int				max_y_tetri(t_tetrimino *tetrimino, int x)
{
	int i;
	int y;

	i = -1;
	y = -1;
	while (++i < 4)
	{
		if (tetrimino->c_pos[i].x == x)
			if (tetrimino->c_pos[i].y > y)
				y = tetrimino->c_pos[i].y;
	}
	return (y + 1);
}

static int		ft_move_vector(int min_sqr, t_tetrimino *t)
{
	t->w_pos.x++;
	if (t->w_pos.y + max_ally_tetri(t) > min_sqr &&
		t->w_pos.x + max_allx_tetri(t) > min_sqr)
		return (0);
	if (t->w_pos.x == min_sqr)
	{
		t->w_pos.y++;
		t->w_pos.x = 0;
	}
	return (1);
}

int				ft_resolve(t_tetrimino *t, int min_sqr
				, char *map)
{
	while (t != NULL)
	{
		while (!(ft_write_tetri_vector(t, map, min_sqr, -1)))
		{
			if (!ft_move_vector(min_sqr, t))
				return (0);
		}
		if (ft_resolve(t->next, min_sqr, map))
			return (1);
		t->next->w_pos = (t_vector2){0, 0};
		ft_suppr_tetri_vector(t, map, min_sqr);
		if (!ft_move_vector(min_sqr, t))
			return (0);
	}
	return (1);
}

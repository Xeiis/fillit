/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:51:45 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/06 11:09:03 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				max_x_line(char **map, int y)
{
	int i;
	int x;

	i = -1;
	x = -1;
	while (map[y][++i] != '\0')
	{
		if (map[y][i] > x)
			x = map[y][i];
	}
	return (x + 1);
}

int				max_x_tetri(t_tetrimino *tetrimino, int y)
{
	int i;
	int x;

	i = -1;
	x = -1;
	while (++i < 3)
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
	while (++i < 3)
	{
		if (tetrimino->c_pos[i].x == x)
			if (tetrimino->c_pos[i].y > y)
				y = tetrimino->c_pos[i].y;
	}
	return (y + 1);
}

int				ft_add_tetri(t_tetrimino *tetrimino, char *map,
		int min_sqr, t_vector2 v)
{
	int y;
	int x;
	int ok;

	ft_init2(&y, &ok, &x);
	while (++y < min_sqr)
		if (max_x_tetri(tetrimino, y) < v.x && max_y_tetri(tetrimino, x) < v.y)
		{
			ok++;
			x++;
		}
	if (x >= max_allx_tetri(tetrimino) && ok >= max_ally_tetri(tetrimino))
		if (ft_test_write(tetrimino, map, v))
			return (ft_write_tetri(tetrimino, map, min_sqr, -1));
	ft_init2(&y, &ok, NULL);
	while (++y < min_sqr)
		if (max_x_line(map, y) + max_x_tetri(tetrimino, y) < min_sqr)
			ok++;
	if (ok >= max_ally_tetri(tetrimino))
		return (ft_write_tetri(tetrimino, map, min_sqr, -1));
	else
		return (0);
}

int				ft_resolve(t_tetrimino *tetrimino, int min_sqr
				, char *map, t_vector2 vector)
{
	if ((ft_add_tetri(tetrimino, map, min_sqr, vector)) == 0)
		return (0);
	else if (tetrimino->next != NULL)
		return (ft_resolve(tetrimino->next, min_sqr, map, vector));
	return (1);
}

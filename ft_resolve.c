/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:51:45 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/08 20:23:55 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				max_x_line(char *map, int y)
{
	int i;
	int x;

	i = -1;
	x = -1;
	while (map[y + (++i)] != '\0')
	{
		if (ft_isupper(map[y + i]))
			if (i > x)
			{	printf("map[y + i]%c, x : %d, y : %d, i : %d\n",map[y + i], x, y ,i);
				x = i;
			}
	}
	return (x + 1);
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
	{
		if (ft_test_write(tetrimino, map, v))
			return (ft_write_tetri(tetrimino, map, min_sqr, -1));
	}
	else
		printf(" x[%d] >= max_allx_tetri(tetrimino)[%d] && ok[%d] >= max_ally_tetri(tetrimino)[%d]\n", x, max_allx_tetri(tetrimino), ok, max_ally_tetri(tetrimino));
	ft_init2(&y, &ok, &x);
	while (++y < min_sqr)
	{
		if (max_x_line(map, y) + max_x_tetri(tetrimino, y) <= min_sqr)
			ok++;
		printf("max_x_line(map, y)[%d] + max_x_tetri(tetrimino, y)[%d] <= min_sqr[%d], y : %d\n", max_x_line(map, y), max_x_tetri(tetrimino, y), min_sqr, y);
	}
	if (ok >= max_ally_tetri(tetrimino))
		return (ft_write_tetri(tetrimino, map, min_sqr, -1));
	else
		printf(" ok[%d] >= max_ally_tetri(tetrimino)[%d]\n", ok, max_ally_tetri(tetrimino));
	//else
		return (0);
}

int				ft_resolve(t_tetrimino **tetrimino, int min_sqr
				, char *map, t_vector2 vector)
{
	t_tetrimino *t;

	t = *tetrimino;
	printf("TETRI : %c\n", t->c);
	printf("VECTOR.X : %d\n", vector.x);
	printf("VECTOR.Y : %d\n", vector.y);
	if ((ft_add_tetri(t, map, min_sqr, vector)) == 0)
		return (0);
	else if (t->next != NULL)
	{
		t = t->next;
		return (ft_resolve(&t, min_sqr, map, vector));
	}
	return (1);
}

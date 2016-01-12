/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:37:58 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/12 19:42:50 by dchristo         ###   ########.fr       */
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
	if (c == '\n' || c == '\0')
		return (1);
	return (0);
}

void				ft_sort_tetri(t_tetrimino **tetri, int x, int y, int i)
{
	t_tetrimino		*t;

	t = *tetri;
	while (t != NULL)
	{
		x = t->c_pos[0].x;
		y = t->c_pos[0].y;
		i = -1;
		while (++i < 3)
		{
			if (t->c_pos[i + 1].x < x)
				x = t->c_pos[i + 1].x;
			if (t->c_pos[i + 1].y < y)
				y = t->c_pos[i + 1].y;
		}
		i = -1;
		while (++i < 4)
		{
			t->c_pos[i].x -= x;
			t->c_pos[i].y -= y;
		}
		t = t->next;
	}
}

int					ft_cmp_tetri(t_vector2 *a, t_vector2 *b)
{
	if (a[0].x == b[0].x &&
		a[1].x == b[1].x &&
		a[2].x == b[2].x &&
		a[3].x == b[3].x &&
		a[0].y == b[0].y &&
		a[1].y == b[1].y &&
		a[2].y == b[2].y &&
		a[3].y == b[3].y)
		return (1);
	return (0);
}

int					max_x_line(char *map, int y, int min_sqr)
{
	int				i;
	int				x;

	i = 0;
	x = -1;
	while (map[y + i * min_sqr] != '\0')
	{
		if (ft_isupper(map[y + i]))
			if (i > x)
				x = i;
		++i;
	}
	return (x + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:37:58 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/11 18:00:32 by ldubos           ###   ########.fr       */
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
	//	ft_putstr("tetri : ");
	//	ft_putchar(t->c);
	//	ft_putchar('\n');
		x = t->c_pos[0].x;
		y = t->c_pos[0].y;
		i = -1;
		while (++i < 3)
		{
	//		ft_putstr("i : ");
	//		ft_putnbr(i);
	//		ft_putchar('\n');
	//		ft_putstr("x : ");
	//		ft_putnbr(t->c_pos[i+1].x);
	//		ft_putchar('\n');
	//		ft_putstr("y : ");
	//		ft_putnbr(t->c_pos[i+1].y);
	//		ft_putchar('\n');
			if (t->c_pos[i + 1].x < x)
				x = t->c_pos[i + 1].x;
			if (t->c_pos[i + 1].y < y)
				y = t->c_pos[i + 1].y;
		}
		i = -1;
		while (++i < 4)
		{
	//		printf("t.x[%d] - x[%d]\n",t->c_pos[i].x, x);
	//		printf("t.y[%d] - y[%d]\n",t->c_pos[i].y, y);
			t->c_pos[i].x -= x;
			t->c_pos[i].y -= y;
		}
		t = t->next;
	}
}

int					ft_test_dlm_over(t_tetrimino t)
{
	if (t.c_pos[0].y - t.c_pos[1].y == -1 &&
		t.c_pos[1].x - t.c_pos[2].x - t.c_pos[3].x < 0 &
		t.c_pos[3].x == t.c_pos[0].x)
		return (1);
	else if (t.c_pos[0].x - t.c_pos[1].x == -1 &&
			t.c_pos[0].x - t.c_pos[1].x - t.c_pos[2].x < 0 &
			t.c_pos[3].x == t.c_pos[0].x)
		return (1);
	return (0);
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
	else if ((tetrimino.c_pos[0].x - tetrimino.c_pos[1].x == -1 ||
			tetrimino.c_pos[0].x - tetrimino.c_pos[1].x == 1) &&
			tetrimino.c_pos[0].y - tetrimino.c_pos[1].y == 0 &&
			(tetrimino.c_pos[2].x - tetrimino.c_pos[3].x == -1 ||
			tetrimino.c_pos[2].x - tetrimino.c_pos[3].x == 1) &&
			tetrimino.c_pos[2].y - tetrimino.c_pos[3].y == 0 &&
			(((tetrimino.c_pos[0].y + tetrimino.c_pos[1].y) -
			(tetrimino.c_pos[2].y + tetrimino.c_pos[3].y)) == -2 ||
			((tetrimino.c_pos[0].y + tetrimino.c_pos[1].y) -
			(tetrimino.c_pos[2].y + tetrimino.c_pos[3].y)) == -2) &&
			(((tetrimino.c_pos[0].x + tetrimino.c_pos[1].x) -
			(tetrimino.c_pos[2].x + tetrimino.c_pos[3].x)) == -2 ||
			((tetrimino.c_pos[0].x + tetrimino.c_pos[1].x) -
			(tetrimino.c_pos[2].x + tetrimino.c_pos[3].x)) == 2))
		return (1);
	else if (ft_test_dlm_over(tetrimino))
		return (1);
	return (0);
}

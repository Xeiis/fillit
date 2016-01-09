/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:36:14 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/09 20:50:25 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int					ft_test(t_tetrimino tetrimino, int i)
{
	int						x_d;
	int						y_d;

	while (i < 3)
	{
		x_d = tetrimino.c_pos[i].x - tetrimino.c_pos[i + 1].x;
		y_d = tetrimino.c_pos[i].y - tetrimino.c_pos[i + 1].y;
		if ((x_d >= -1 && x_d <= 1 && y_d == 0) ||
			(y_d >= -1 && y_d <= 1 && x_d == 0))
			++i;
		else if (x_d >= -1 && x_d <= 1 && y_d >= -1 && y_d <= 1)
		{
			x_d = tetrimino.c_pos[i].x - tetrimino.c_pos[i + 2].x;
			y_d = tetrimino.c_pos[i].y - tetrimino.c_pos[i + 2].y;
			if ((x_d >= -1 && x_d <= 1 && y_d == 0) ||
				(y_d >= -1 && y_d <= 1 && x_d == 0) ||
				ft_test_dlm(tetrimino, i))
				++i;
			else
				return (0);
		}
		else if (ft_test_dlm(tetrimino, i))
			++i;
		else
			return (0);
	}
	return (1);
}

static	void				ft_init(int *x, int *y, int *i, int *boucle)
{
	*x = 0;
	*y = 0;
	*i = 0;
	*boucle = 0;
}

static	int					ft_statement(char *str, t_tetrimino *tetrimino)
{
	int						x;
	int						y;
	int						i;
	int						b;

	ft_init(&x, &y, &i, &b);
	while (*++str && i < 5 && (*str == '#' || *str == '.' || *str == '\n'))
	{
		if (*str == '\n')
		{
			if (!ft_is_back_line(&y, &x))
				return (0);
		}
		else if (*str == '#' && *str != '.')
		{
			tetrimino->c_pos[i].x = x;
			tetrimino->c_pos[i++].y = y;
		}
		(*str == '.' || *str == '#') ? x++ : x;
		b++;
	}
	if (!ft_isvalidchar(*--str) || i > 4 || (b != 21 && b != 20))
		return (0);
	return (1);
}

static int					ft_read(int fd, int i, char *buf, t_tetrimino **ret)
{
	t_tetrimino				*t;

	buf = ft_strnew(BUF_S);
	t = *ret;
	while (read(fd, buf, BUF_S) != 0)
	{
		if (i != 0)
		{
			if (!(t->next = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
				return (0);
			t = t->next;
		}
		if (!(ft_statement(--buf, t)))
			return (0);
		t->c = 'A' + i;
		if (!(ft_test(*t, 0)))
			return (0);
		ft_bzero(buf, BUF_S + 1);
		++i;
	}
	t->next = NULL;
	return (1);
}

int							ft_gettab(const char *path, t_tetrimino **t)
{
	int						fd;
	
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	return (ft_read(fd, 0, NULL, t));
}

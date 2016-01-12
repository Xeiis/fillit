/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:36:14 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/12 19:49:12 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int					ft_test(t_tetrimino t)
{
	int						i;
	t_tetrimino				*tab;

	tab = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	tab[0] = (t_tetrimino){.c_pos = {t.c_pos[0], t.c_pos[1],
			t.c_pos[2], t.c_pos[3]}, .w_pos = {0, 0},
			.next = NULL, .c = t.c};
	ft_sort_tetri(&tab, 0, 0, 0);
	i = 0;
	while (i < 19)
	{
		if (ft_cmp_tetri(tab[0].c_pos, (t_vector2 *)&all_t[i++]))
		{
			free(tab);
			return (1);
		}
	}
	free(tab);
	return (0);
}

static	void				ft_init(int *x, int *y, int *i)
{
	*x = 0;
	*y = 0;
	*i = 0;
}

static	int					ft_statement(char *str, t_tetrimino *tetrimino,
		int b)
{
	int						x;
	int						y;
	int						i;

	ft_init(&x, &y, &i);
	str[b] = '\0';
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
	}
	if (i > 4 || ((b == 21 && *--str != '\n') || (b == 20 && *str != '\0')))
		return (0);
	return (1);
}

static int					ft_read(int fd, int i, t_tetrimino **ret, int b)
{
	t_tetrimino				*t;
	char					*buf;
	int						b_save;

	buf = ft_strnew(BUF_S);
	t = *ret;
	while ((b = read(fd, buf, BUF_S)) != 0)
	{
		if (i != 0)
		{
			if (!(t->next = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
				return (0);
			t = t->next;
		}
		if (!(ft_statement(--buf, t, b)))
			return (0);
		t->c = 'A' + i++;
		if (!(ft_test(*t)))
			return (0);
		b_save = b;
	}
	if (b_save != 20)
		return (0);
	t->next = NULL;
	return (1);
}

int							ft_gettab(const char *path, t_tetrimino **t)
{
	int						fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	return (ft_read(fd, 0, t, 0));
}

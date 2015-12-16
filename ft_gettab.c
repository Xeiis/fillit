/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:36:14 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/16 17:55:18 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft/libft.h"

#include <stdio.h>

static	int					ft_test(t_tetrimino tetrimino)
{
	int						i;
	int						x_d;
	int						y_d;

	i = 0;
	while (i < 3)
	{
		x_d = tetrimino.c_pos[i].x - tetrimino.c_pos[i + 1].x;
		y_d = tetrimino.c_pos[i].y - tetrimino.c_pos[i + 1].y;
		printf("1 |%d x_a => [%d] | x_b => [%d]\n",i , tetrimino.c_pos[i].x, tetrimino.c_pos[i + 1].x);
		printf("1 |%d y_a => [%d] | y_b => [%d]\n",i , tetrimino.c_pos[i].y, tetrimino.c_pos[i + 1].y);
		if ((x_d >= -1 && x_d <= 1 && y_d == 0) ||
			(y_d >= -1 && y_d <= 1 && x_d == 0))
			++i;
		else if (x_d >= -1 && x_d <= 1 && y_d >= -1 && y_d <= 1)
		{
			x_d = tetrimino.c_pos[i].x - tetrimino.c_pos[i + 2].x;
			y_d = tetrimino.c_pos[i].y - tetrimino.c_pos[i + 2].y;
			printf("2 | x_a => [%d] | x_b => [%d]\n", tetrimino.c_pos[i].x, tetrimino.c_pos[i + 2].x);
			printf("2 | y_a => [%d] | y_b => [%d]\n", tetrimino.c_pos[i].y, tetrimino.c_pos[i + 2].y);
			if ((x_d >= -1 && x_d <= 1 && y_d == 0) ||
				(y_d >= -1 && y_d <= 1 && x_d == 0))
				++i;
			else
			{
				printf("x_d => [%d]\n", x_d);
				printf("y_d => [%d]\n", y_d);
				return (0);	
			}
		}
		else
		{
			printf("x_d => [%d]\n", x_d);
			printf("y_d => [%d]\n", y_d);
			return (0);
		}
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
			x = 0;
			++y;
		}
		else if (*str == '#' && *str != '.')
		{
			printf("[%d]x = %d\n", i,x);
			printf("[%d]y = %d\n", i,y);
			tetrimino->c_pos[i].x = x++;
			tetrimino->c_pos[i++].y = y;
		}
		else if (*str == '.')
			++x;
		b++;
	}
	if (!ft_isvalidchar(*--str) || i > 4 || (b != 21 && b != 20))
		return (0);
	return (1);
}

static	t_tetrimino			*ft_read(int fd)
{
	char					*buf;
	int						i;
	t_tetrimino				*ret;
	t_tetrimino				*tmp;

	i = 0;
	buf = ft_strnew(BUF_S);
	ft_bzero(buf, BUF_S);
	if (!(ret = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	while (read(fd, buf, BUF_S) != 0)
	{
		if (!(ft_statement(--buf, ret)))
			return (NULL);
		ret->c = 'A' + i;
		if (!(ft_test(*ret)))
			return (NULL);
		if (!(tmp = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
			return (NULL);
		ret->next = tmp;
		ret = ret->next;
		ft_bzero(buf, BUF_S);
		++i;
	}
	return (ret);
}

t_tetrimino					*ft_gettab(const char *path)
{
	int						fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	return (ft_read(fd));
}

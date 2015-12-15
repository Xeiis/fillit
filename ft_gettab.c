/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:36:14 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/15 16:36:45 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft/libft.h"

int					ft_test(t_tetrimino tetrimino)
{
	int				i;
	int				x_d;
	int				y_d;

	i = 0;
	while (i < 3)
	{
		x_d = tetrimino.c_pos[i].x - tetrimino.c_pos[i + 1].x;
		y_d = tetrimino.c_pos[i].y - tetrimino.c_pos[i + 1].y;
		if ((x_d >= -1 && x_d <= 1 && y_d == 0) ||
			(y_d >= -1 && y_d <= 1 && x_d == 0))
			++i;
		else if (i >= 1)
		{
			x_d = tetrimino.c_pos[i - 1].x - tetrimino.c_pos[i].x;
			y_d = tetrimino.c_pos[i - 1].y - tetrimino.c_pos[i].y;
			if (y_d >= -1 && y_d <= 1 && x_d >= -1 && x_d <= 1)
				++i;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

void				ft_statement(char *str, t_tetrimino tetrimino)
{
	size_t			x;
	size_t			y;
	size_t			i;

	x = 0;
	y = 0;
	i = 0;
	while (*str++)
		if (*str == '\n')
		{
			x = 0;
			++y;
		}
		else if (*str != '#' && *str != '.' && *str && i < 4)
		{
			write(1, "error\n", 6);
			break ;
		}
		else if (*str == '#' && *str != '.')
		{
			tetrimino.c_pos[i].x = x++;
			tetrimino.c_pos[i++].y = y;
		}
		else
			++x;
}

t_tetrimino			*ft_read(int fd)
{
	char			*buf;
	size_t			i;
	t_tetrimino		*ret;

	i = 0;
	//if (!(ret = (t_tetrimino *)malloc(sizeof(t_tetrimino) * 26)))
	//	return (NULL);
	// faire la liste chaines
	while (read(fd, buf, BUF_S) != 0)
	{
		ft_statement(buf, ret[i]);
		ret[i].c = 'A' + i;
		++i;
	}
}

t_tetrimino			*ft_gettab(const char *path)
{
	int				fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	return (ft_read(fd));
}

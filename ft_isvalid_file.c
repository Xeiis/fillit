/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:29:07 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/10 19:33:06 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <fillit.h>

static t_tetrimino	ft_statement(size_t len, t_tetrimino *tetriminos)
{
	t_tetrimino		*ret;
	size_t			i;

	ret = (t_tetrimino *)malloc(sizeof(t_tetrimino) * len);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = tetriminos[i];
		++i;
	}
	return (ret);
}

static t_tetrimino	ft_read_loop(int fd, char *buf, size_t x, size_t y)
{
	size_t			buf_s;
	size_t			i;
	size_t			j;
	size_t			cell;
	t_tetrimino		tetriminos[26];

	j = 0;
	while (1)
	{
		cell = 0;
		x = 0;
		y = 0;
		i = 0;
		(buf && buf[BUF_S]) ? buf_s = BUF_S : buf_s = BUF_S + 1;
		buf = (char *)malloc(sizeof(char) * buf_s);
		if (buf[buf_s])
			read(fd, buf, buf_s);
		tetriminos[j].c = 'A' + j;
		while (i < buf_s)
		{
			if (buf[i] == '\n')
			{
				++y;
				++i;
			}
			if (buf[i] == '#' && buf[i] != '.' && cell < 4)
			{
				tetriminos[j]->lpos[i].x = x;
				tetriminos[j]->lpos[i].y = y;
				++cell;
			}
			else if (buf[i] != '#' || buf[i] != '.' || cell > 4)
				return (NULL);
			++x;
			++i;
		}
		++j;
	}
	return (ft_statement(j, tetriminos));
}

t_tetrimino			ft_isvalid_file(const char *path)
{
	const int		fd = open(path);
	char			*buf;
	size_t			x;
	size_t			y;

	if (fd != -1)
		return (ft_read_loop(fd, buf, x, y));
	return (NULL);
}

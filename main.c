/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:18:39 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/06 11:09:05 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_min_sqr(t_tetrimino *tetrimino, int i)
{
	while (tetrimino->next != NULL)
	{
		i++;
		tetrimino = tetrimino->next;
	}
	return (2 * ((int)((ft_sqrt((i * 4), 0.01) + 0.5))));
}

static int			ft_map(char **map, int min_sqr, int i)
{
	free(*map);
	if ((*map = ft_strnew(min_sqr * 5)) == NULL)
		return (0);
	return (1);
}

static int			ft_resolve_it(t_tetrimino *tetrimino, char **map,
									int min_sqr, int result)
{
	t_vector2 vector;

	min_sqr = ft_min_sqr(tetrimino, 0);
	if (!ft_map(map, min_sqr, -1))
		return (0);
	vector.x = 0;
	vector.y = 0;
	while ((result = (ft_resolve(tetrimino, min_sqr, *map, vector))) != 1)
	{
		if (result == 0)
		{
			if (max_allx_tetri(tetrimino) + vector.x + 1 > min_sqr)
			{
				vector.x = 0;
				vector.y++;
			}
			else
				vector.x++;
			if (max_ally_tetri(tetrimino) + vector.y > min_sqr)
				if (!ft_map(map, min_sqr + 1, -1))
					return (0);
		}
	}
	return (min_sqr);
}

int					main(int argc, char **argv)
{
	t_tetrimino		*t;
	char			*map;
	int				min_sqr;

	if (!(t = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (0);
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		t = ft_gettab(argv[1]);
		if (!t)
			write(1, "error\n", 6);
		else
		{
			ft_sort_tetri(t);
			if (!(min_sqr = ft_resolve_it(t, &map, 0, 0)))
			{
				write(1, "error\n", 6);
				return (0);
			}
		//	ft_affichage_solution(map, min_sqr);
			write(1, "ok\n", 3);
		}
	}
	return (0);
}

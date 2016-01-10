/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:18:39 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/10 20:03:27 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_min_sqr(t_tetrimino **tetrimino, int i)
{
	t_tetrimino *t;

	t = *tetrimino;
	while (t->next != NULL)
	{
		i++;
		t = t->next;
	}
	return (((int)((ft_sqrt((i * 4), 0.01) + 0.5))));
}

static int			ft_map(char **map, int min_sqr, int i)
{
	free(*map);
	//printf("taille map : %d\n", min_sqr * min_sqr);
	if ((*map = ft_strnew(min_sqr * min_sqr)) == NULL)
		return (0);
	return (1);
}

static int			ft_resolve_it(t_tetrimino **tetrimino, char **map,
		int min_sqr)
{
	ft_putendl("5test");
	min_sqr = ft_min_sqr(tetrimino, 1);
	ft_putendl("6test");
	if (!ft_map(map, min_sqr, -1))
		return (0);
	ft_putendl("7test");
	while (((ft_resolve(tetrimino, min_sqr, *map))) != 1)
	{
		ft_putendl("8test");
		ft_vector_init(tetrimino);
		min_sqr++;
		//printf("MIN SQR[%d]\n", min_sqr);
		if (!ft_map(map, min_sqr, -1))
			return (0);
	}
	return (min_sqr);
}
#include <time.h>
int					main(int argc, char **argv)
{
	/*float temps;
	clock_t t1, t2;

	t1 = clock();
	*/
	t_tetrimino		*t;
	char			*map;
	int				min_sqr;
	
	if ((t = (t_tetrimino *)malloc(sizeof(t_tetrimino))) == NULL)
		return (0);
	ft_putendl("test");
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
	ft_putendl("1test");
		if(!ft_gettab(argv[1], &t))
		{
			write(1, "error\n", 6);
			return (0);
		}
	ft_putendl("2test");
		//t->c = 'A';
		printf("tetri : %c\n",t->c);
		printf("tetri x : %d\n",t->w_pos.x);
		printf("tetri y : %d\n",t->w_pos.y);
	ft_putendl("3test");
		ft_sort_tetri(&t, 0, 0 ,0);
	ft_putendl("4test");
		if (!(min_sqr = ft_resolve_it(&t, &map, 0)))
		{
			write(1, "error\n", 6);
			return (0);
		}
		ft_affichage_solution(map, min_sqr);
		write(1, "ok\n", 3);
	}
	/*t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps = %f\n", temps);
	*/return (0);
}

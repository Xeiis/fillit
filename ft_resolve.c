/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:51:45 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/10 20:04:08 by dchristo         ###   ########.fr       */
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
			{//	printf("map[y + i]%c, x : %d, y : %d, i : %d\n",map[y + i], x, y ,i);
				x = i;
			}
	}
	return (x + 1);
}
int				max_y_line(char *map, int x, int min_sqr)
{
	int i;
	int y;

	y = -1;
	i = 0;
	while (map[x + i * min_sqr] != '\0')
	{
		if (ft_isupper(map[x + i]))
			if (i > y)
			{//	printf("map[y + i]%c, x : %d, y : %d, i : %d\n",map[y + i], x, y ,i);
				y = i;
			}
		i++;
	}
	return (y + 1);
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

/*int				ft_add_tetri(t_tetrimino *tetrimino, char *map,
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
		//printf(" x[%d] >= max_allx_tetri(tetrimino)[%d] && ok[%d] >= max_ally_tetri(tetrimino)[%d]\n", x, max_allx_tetri(tetrimino), ok, max_ally_tetri(tetrimino));
	ft_init2(&y, &ok, &x);
	while (++y < min_sqr)
	{
		if (max_x_line(map, y) + max_x_tetri(tetrimino, y) <= min_sqr)
			ok++;
	//	printf("max_x_line(map, y)[%d] + max_x_tetri(tetrimino, y)[%d] <= min_sqr[%d], y : %d\n", max_x_line(map, y), max_x_tetri(tetrimino, y), min_sqr, y);
	}
	if (ok >= max_ally_tetri(tetrimino))
		return (ft_write_tetri(tetrimino, map, min_sqr, -1));
	else
	//	printf("ok[%d] >= max_ally_tetri(tetrimino)[%d]\n", ok, max_ally_tetri(tetrimino));
	//else
		return (0);
}*/

static int		ft_move_vector(int min_sqr, t_tetrimino *t)
{
	t->w_pos.x++;
	if (t->w_pos.x == min_sqr)
	{
		t->w_pos.y++;
		t->w_pos.x = 0;
	}
	if (t->w_pos.y + max_ally_tetri(t) > min_sqr &&
		t->w_pos.x + max_allx_tetri(t) > min_sqr)
	{
		//printf("%d + %d > %d\n",t->w_pos.y, max_ally_tetri(t), min_sqr);
		//printf("%d + %d > %d\n",t->w_pos.x, max_allx_tetri(t), min_sqr);
	//	printf("je sort move vector\n");
		return (0);
	}
	return (1);
}

int				ft_resolve(t_tetrimino **tetrimino, int min_sqr
				, char *map)
{
	t_tetrimino *t;

	t = *tetrimino;
	ft_putendl("8test");
	while (t != NULL)
	{
		ft_putendl("9test");
		printf("je rentre\n");
		printf("TETRI : %c\n", t->c);
		printf("TETRI X : %d\n", t->w_pos.x);
		printf("TETRI Y : %d\n", t->w_pos.y);
		while (!(ft_write_tetri_vector(t, map, min_sqr)))
		{
			ft_putendl("10test");
		/*	printf("pas de place\n");
			printf("tetri : %c\n", t->c);
			printf("tetri x : %d\n", t->w_pos.x);
			printf("tetri y : %d\n", t->w_pos.y);
		*/	if (!ft_move_vector(min_sqr, t))
				return (0);
		}
		ft_putendl("11test");
		//ft_affichage_solution(map, min_sqr);
		//printf("je sort du while\n");
		if (ft_resolve(&(t->next), min_sqr, map))
			return (1);
		ft_putendl("12test");
		//printf("je suis apres le resolve\n");
		ft_suppr_tetri_vector(t, map, min_sqr);
		ft_putendl("13test");
		ft_vector_init(&(t->next));
		ft_putendl("14test");
		if (!ft_move_vector(min_sqr, t))
			return (0);
		ft_putendl("15test");
		//printf("je suis apres le move\n");
	}
	//printf("return 1\n");
	return (1);
}

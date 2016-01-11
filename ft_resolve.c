/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:51:45 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/11 16:54:10 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				max_x_line(char *map, int y, int min_sqr)
{
	int i;
	int x;

	i = 0;
	x = -1;
	while (map[y + i * min_sqr] != '\0')
	{
		if (ft_isupper(map[y + i]))
			if (i > x)
			{//	printf("map[y + i]%c, x : %d, y : %d, i : %d\n",map[y + i], x, y ,i);
				x = i;
			}
		++i;
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
		++i;
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
	FILE * fichier;
	fichier = fopen("result.txt", "a");
	while (t != NULL)
	{
		//printf("je rentre\n");
		//printf("TETRI : %c\n", t->c);
		//printf("TETRI X : %d\n", t->w_pos.x);
		//printf("TETRI Y : %d\n", t->w_pos.y);
		while (!(ft_write_tetri_vector(t, map, min_sqr)))
		{
		//	printf("pas de place\n");
		//	printf("tetri : %c\n", t->c);
		//	printf("tetri x : %d\n", t->w_pos.x);
		//	printf("tetri y : %d\n", t->w_pos.y);
			if (!ft_move_vector(min_sqr, t))
			{fclose(fichier);
				return (0);
			}
		}
		ft_affichage_solution_in_file(map, min_sqr);
		//printf("je sort du while\n");
		if (ft_resolve(&(t->next), min_sqr, map))
		{
			fclose(fichier);
			return (1);
		}
		//printf("je suis apres le resolve\n");
		ft_suppr_tetri_vector(t, map, min_sqr);
		ft_vector_init(&(t->next));
		if (!ft_move_vector(min_sqr, t))
		{
			fclose(fichier);
			return (0);
		}
	//	printf("je suis apres le move\n");
	}
	fclose(fichier);
	//printf("return 1\n");
	return (1);
}

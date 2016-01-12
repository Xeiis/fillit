/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:56:22 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/12 20:01:20 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_S 21

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_vector2
{
	int					x;
	int					y;
}						t_vector2;

typedef struct			s_tetrimino
{
	t_vector2			c_pos[4];
	t_vector2			w_pos;
	struct s_tetrimino	*next;
	char				c;
}						t_tetrimino;

static const t_vector2	g_all_t[19][4] = {
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 2, .y = 0},
		{.x = 3, .y = 0}
	},
	{
		{.x = 0, .y = 0},
		{.x = 0, .y = 1},
		{.x = 0, .y = 2},
		{.x = 0, .y = 3}
	},
	{
		{.x = 0, .y = 0},
		{.x = 0, .y = 1},
		{.x = 0, .y = 2},
		{.x = 1, .y = 2}
	},
	{
		{.x = 1, .y = 0},
		{.x = 1, .y = 1},
		{.x = 0, .y = 2},
		{.x = 1, .y = 2}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 0, .y = 1},
		{.x = 0, .y = 2}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 1, .y = 1},
		{.x = 1, .y = 2}
	},
	{
		{.x = 0, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 2, .y = 1}
	},
	{
		{.x = 2, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 2, .y = 1}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 2, .y = 0},
		{.x = 0, .y = 1}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 2, .y = 0},
		{.x = 2, .y = 1}
	},
	{
		{.x = 1, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 1, .y = 2}
	},
	{
		{.x = 1, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 2, .y = 1}
	},
	{
		{.x = 0, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 0, .y = 2}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 2, .y = 0},
		{.x = 1, .y = 1}
	},
	{
		{.x = 0, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 1, .y = 2}
	},
	{
		{.x = 1, .y = 0},
		{.x = 2, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1}
	},
	{
		{.x = 1, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1},
		{.x = 0, .y = 2}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 1, .y = 1},
		{.x = 2, .y = 1}
	},
	{
		{.x = 0, .y = 0},
		{.x = 1, .y = 0},
		{.x = 0, .y = 1},
		{.x = 1, .y = 1}
	}
};

double					ft_sqrt(double n, double i);
int						ft_gettab(const char *path, t_tetrimino **t);
int						ft_isvalidchar(char c);
int						ft_is_back_line(int *y, int *x);
void					ft_sort_tetri(t_tetrimino **tetri, int x, int y, int i);
void					ft_affichage(t_tetrimino *tetrimino);
int						ft_test_dlm(t_tetrimino tetrimino, int i);
int						ft_resolve(t_tetrimino *t, int min_sqr,
		char *map);
int						max_allx_tetri(t_tetrimino *tetrimino);
int						max_ally_tetri(t_tetrimino *tetrimino);
int						max_x_tetri(t_tetrimino *tetrimino, int y);
int						max_y_tetri(t_tetrimino *tetrimino, int x);
void					ft_init2(int *y, int *ok, int *x);
int						ft_write_tetri_vector(t_tetrimino *
		tetrimino, char *map, int min_sqr, int i);
void					ft_affichage_solution(char *map, int min_sqr);
void					ft_suppr_tetri_vector(t_tetrimino *t, char *map,
		int min_sqr);
int						max_x_line(char *map, int y, int min_sqr);
int						max_y_line(char *map, int x, int min_sqr);
int						ft_cmp_tetri(t_vector2 *a, t_vector2 *b);

void					ft_affichage_solution_in_file(char *map, int min_sqr);
#endif

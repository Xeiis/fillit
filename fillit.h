/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:56:22 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/05 04:32:38 by dchristo         ###   ########.fr       */
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

double					ft_sqrt(double n, double i);
t_tetrimino				*ft_gettab(const char *path);
int						ft_isvalidchar(char c);
int						ft_is_back_line(int *y, int *x);
void					ft_sort_tetri(t_tetrimino *tetrimino);
void					ft_affichage(t_tetrimino *tetrimino);
int						ft_test_dlm(t_tetrimino tetrimino, int i);
int						ft_resolve(t_tetrimino *tetrimino, int min_sqr,
		char **map, t_vector2 vector);
int						max_allx_tetri(t_tetrimino *tetrimino);
int						max_ally_tetri(t_tetrimino *tetrimino);
int						max_x_tetri(t_tetrimino *tetrimino, int y);
int						max_y_tetri(t_tetrimino *tetrimino, int x);
void					ft_init2(int *y, int *ok, int *x);
int						ft_test_write(t_tetrimino *tetrimino, char **map,
		t_vector2 vector);
int						ft_write_tetri(t_tetrimino *tetrimino, char **map,
		int min_sqr, int i);
void					ft_affichage_solution(char **map, int min_sqr);
#endif

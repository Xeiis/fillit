/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:56:22 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/15 16:50:08 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_S 21

typedef struct			s_vector2
{
	int					x;
	int					y;
}						t_vector2;

typedef struct			s_tetrimino
{
	t_vector2			c_pos[4];
	t_vector2			w_pos;
	struct s_tetrimino 	*next;
	char				c;
}						t_tetrimino;

#endif

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

# define BUF_S 20

typedef struct		s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct		s_tetrimino
{
	t_vector2		c_pos[4];
	t_vector2		w_pos;
	char			c;
}					t_tetrimino;

#endif

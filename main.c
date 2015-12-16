/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:18:39 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/16 15:11:49 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

#define DEFAULT   "\033[0m"
#define HIGHLIGHT "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define BLACK     "\033[30m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define PURPLE    "\033[35m"
#define CYAN      "\033[36m"
#define WHITE     "\033[37m"

void				ft_square(int argc, char **argv)
{
	int		i;

	i = 1;
	printf(HIGHLIGHT PURPLE "\t\t\t/* ************************************************************************** */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                                                                            */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                                                                            */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                             FILLIT DO IT                                   */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                                                                            */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                                                                            */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/* ************************************************************************** */\n" DEFAULT);
	printf("Square(s) => %d\n\n", argc - 1);
	if (argc < 2)
		printf(HIGHLIGHT RED "/!\\ Too few arguments /!\\" DEFAULT);
	else
		while (i < argc)
		{
			printf("[Square(" CYAN "%d" DEFAULT  ")]{nbr of tetrimino(s) = %i}\t\t=>\t\tMin square size[" CYAN "%zu x %zu" DEFAULT "]\n", i, ft_atoi(argv[i]), (size_t)(ft_sqrt((ft_atoi(argv[i]) * 4), 0) + 0.5), (size_t)(ft_sqrt((ft_atoi(argv[i]) * 4), 0) + 0.5));
			++i;
		}
}

int					main(int argc, char **argv)
{
	t_tetrimino		*t;
	if (!(t = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (0);
	//ft_square(argc, argv); // calculer le nombre de tetris pour utiliser la fonction
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		t = ft_gettab(argv[1]);
		if(!t)
			write(1, "error\n", 6);
		else
			write(1, "ok\n", 3);
		// algo pour resolution
		// afficher la solution
	}
	return (0);
}

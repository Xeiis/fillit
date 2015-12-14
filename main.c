/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:18:39 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/14 17:52:58 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft/libft.h"

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

double				ft_sqrt(double n, double i);

int					main(int argc, char **argv)
{
	int		i;

	i = 1;
	printf(HIGHLIGHT PURPLE "\t\t\t/* ************************************************************************** */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                                                                            */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*                                                                            */\n");
	printf(HIGHLIGHT PURPLE "\t\t\t/*   Created: 2015/12/07 13:18:39 by ldubos                                   */\n");
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
	return (0);
}

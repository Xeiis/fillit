# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:26:37 by dchristo          #+#    #+#              #
#    Updated: 2016/01/05 05:26:28 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = #-Wall -Werror -Wextra

SRC = $(shell ls -1 | grep "\.c")

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(NAME) 
 
$(NAME): 
	@cd libft ; $(MAKE) -f Makefile
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo "\033[5;31;40m";
	@echo "+---------------------------------------------+";
	@echo "|   ______ _____ _      _      _____ _______  |";
	@echo "|  |  ____|_   _| |    | |    |_   _|__   __| |";
	@echo "|  | |__    | | | |    | |      | |    | |    |";
	@echo "|  |  __|   | | | |    | |      | |    | |    |";
	@echo "|  | |     _| |_| |____| |____ _| |_   | |    |";
	@echo "|  |_|    |_____|______|______|_____|  |_|    |";
	@echo "|                                             |";
	@echo "+------------------------by dchristo & ldubos-+";
	
%.o : %.c
	$(CC) $(FLAGS) $< -o $@

clean:	
	rm -rf $(OBJS)
	@cd libft ; $(MAKE) clean -f Makefile

fclean:	clean
	rm -f $(NAME)
	@cd libft ; $(MAKE) fclean -f Makefile	
	
re:	fclean all

.PHONY: all clean fclean re

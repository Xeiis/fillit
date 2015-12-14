# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:26:37 by ldubos            #+#    #+#              #
#    Updated: 2015/12/14 17:29:41 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = $(shell ls -1 | grep "\.c")

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(NAME) 
 
$(NAME): 
	@git clone vogsphere@vogsphere.42.fr:intra/2015/activities/libft/dchristo2 libft
	@cd libft ; $(MAKE) -f Makefile
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo "+---------------------------------------------+";
	@echo "|   ______ _____ _      _      _____ _______  |";
	@echo "|  |  ____|_   _| |    | |    |_   _|__   __| |";
	@echo "|  | |__    | | | |    | |      | |    | |    |";
	@echo "|  |  __|   | | | |    | |      | |    | |    |";
	@echo "|  | |     _| |_| |____| |____ _| |_   | |    |";
	@echo "|  |_|    |_____|______|______|_____|  |_|    |";
	@echo "|                                             |";
	@echo "+---------------------------------------------+";
	
%.o : %.c
	$(CC) $(FLAGS) $< -o $@

clean:	
	rm -rf $(OBJS)
	@cd libft ; $(PHONY make clean)

fclean:	clean
	rm -f $(NAME)
	@cd libft ; $(PHONY make fclean)	
	rm -rf libft
	
re:	fclean all write

write:
	@echo "+---------------------------------------------+";
	@echo "|   ______ _____ _      _      _____ _______  |";
	@echo "|  |  ____|_   _| |    | |    |_   _|__   __| |";
	@echo "|  | |__    | | | |    | |      | |    | |    |";
	@echo "|  |  __|   | | | |    | |      | |    | |    |";
	@echo "|  | |     _| |_| |____| |____ _| |_   | |    |";
	@echo "|  |_|    |_____|______|______|_____|  |_|    |";
	@echo "|                                             |";
	@echo "+---------------------------------------------+";

.PHONY: all clean fclean re write

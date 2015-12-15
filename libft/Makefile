# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:26:37 by ldubos            #+#    #+#              #
#    Updated: 2015/12/15 17:22:48 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -I . -c

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_islower.c \
	   ft_isprint.c \
	   ft_isupper.c \
	   ft_isblank.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncpy.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_islowercase.c \
	   ft_isuppercase.c \
	   ft_isspace.c \
	   ft_tolowercase.c \
	   ft_touppercase.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	ar rc  $(NAME) $(OBJS) 
	ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) $< -o $@

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all write

write:
	@echo "+---------------------------------------+";
	@echo "|   _      _____ ____  ______ _______   |";
	@echo "|  | |    |_   _|  _ \|  ____|__   __|  |";
	@echo "|  | |      | | | |_) | |__     | |     |";
	@echo "|  | |      | | |  _ <|  __|    | |     |";
	@echo "|  | |____ _| |_| |_) | |       | |     |";
	@echo "|  |______|_____|____/|_|       |_|     |";
	@echo "|                                       |";
	@echo "+---------------------------------------+";

.PHONY: all clean fclean re

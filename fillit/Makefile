# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/29 15:50:45 by sharris           #+#    #+#              #
#    Updated: 2018/07/29 15:50:45 by sharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = -L../libft -lft
LIBFT = ../libft/libft.a

INC = -I .
SRCS =	fillit_usage.c \
	ft_fillit.c \
	ft_readfile.c \
	ft_validateshapes.c \
	main.c \
	optimize_shapes.c \
	fillit_solve.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(INC) $(OBJ) $(LIB) -o $(NAME)

$(LIBFT):
	make -C ../libft

clean:
	rm -f $(OBJ)
	make clean -C ../libft

fclean:
	rm -f $(NAME)
	make fclean -C ../libft

re: fclean all

.PHONY : all, re, clean, fclean




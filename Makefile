# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/29 15:50:45 by sharris           #+#    #+#              #
#    Updated: 2018/08/10 16:41:27 by sharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for
NAME = fillit

# Fillit files
FILLIT_DIR = ./fillit_src
SRCS_FILES =	fillit_usage.c \
	ft_fillit.c \
	ft_readfile.c \
	ft_validateshapes.c \
	main.c \
	optimize_shapes.c \
	fillit_solve.c \
	box_util.c
SRCS = $(addprefix $(FILLIT_DIR)/,$(SRCS_FILES))
OBJ = $(SRCS:.c=.o)

# Libft files
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = -I $(FILLIT_DIR)
LIB = -L./libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(INC) $(OBJ) $(LIB) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	echo Make Clean
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY : all, re, clean, fclean




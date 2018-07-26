# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefil                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 20:43:31 by aalhomai          #+#    #+#              #
#    Updated: 2018/06/25 20:57:10 by aalhomai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FILES	= *.c
OBJ		= *.o

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		gcc -Wall -Wextra -Werror -c $(FILES)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

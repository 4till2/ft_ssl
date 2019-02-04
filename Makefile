# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserkez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 16:14:56 by yserkez           #+#    #+#              #
#    Updated: 2018/11/15 16:15:38 by yserkez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
SRC = *.c
OBJ = $(SRC:.c=.o)
SRC_PATH = src/
SRC_POS = $(addprefix $(SRC_PATH),$(SRC))
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

$(NAME): makelib
	 gcc $(FLAGS) -o $(NAME) $(SRC_POS) $(LIB);

all: $(NAME)

makelib:
	make -C libft/

clean:
	rm -rf $(OBJ) libft/$(OBJ)

fclean: clean
	rm -rf $(NAME) libft/libft.a

re: fclean all

.PHONY : all, re, clean, fclean

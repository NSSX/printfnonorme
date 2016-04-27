# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avella <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:17:03 by avella            #+#    #+#              #
#    Updated: 2015/11/27 12:09:02 by avella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_printf

CC = gcc

INCLUDES = "libft/includes"

FLAGS = -Wall -Wextra


SRC = converter.c conv_arg.c first_arg.c largeur_minimum.c \
	long_short.c main.c precision.c printf.c my_itoa.c \
	my_utoa.c wchar.c

LIB = libftprintf.a

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) :
	make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -I $(INCLUDES)
clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all


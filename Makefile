# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 16:36:05 by akaplyar          #+#    #+#              #
#    Updated: 2017/02/27 15:50:21 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = fdf.o map.o draw.o cords.o hook.o zoom.o #moves.o

HEADER = fdf.h

TARGET = am

all:$(OBJ)
	cc -o $(TARGET) $(OBJ) -I $(HEADER) -lmlx -L./libft/ -lft -framework OpenGL -framework AppKit
clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(TARGET)

re: fclean all

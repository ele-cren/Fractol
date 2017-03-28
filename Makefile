# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 15:45:28 by ele-cren          #+#    #+#              #
#    Updated: 2017/03/28 12:42:49 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fractol

PATH_SRC = ./src/

SRC = src/draw.c src/main.c src/fract.c src/event.c src/init.c

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -Ofast -I includes -I libft/includes -I \
		/usr/local/include

LIBS = -L./libft -lft -framework OpenGL -framework AppKit \
	   -L /usr/local/lib/ -lmlx

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
	echo "\033[32m[✔] \033[0mFractol"

obj/%.o : src/%.c
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@
	echo "\033[32m[✔] \033[0m$@"

.PHONY : clean fclean

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31m[✗] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31m[✗] \033[0m$(NAME)"

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:11:14 by wmardin           #+#    #+#              #
#    Updated: 2022/08/31 11:21:12 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OS = $(shell uname)

ifeq ($(OS), Linux)
MLXFLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -DKEY_ESC=65307
else
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -DKEY_ESC=53
endif

NAME =	fract-ol
SRC =	main.c put.c circtal.c mod_01.c

%.o: %.c

LIBFT = libft/libft.a

#all:
#	gcc $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o fractol

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo '$(NAME) created.'

$(LIBFT):
	@make --no-print-directory -C ./libft

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo 'clean performed.'

fclean: clean
	@$(RM) $(NAME) $(LIBFT) a.out
	@echo 'fclean performed.'

re: fclean all

noflag:
	@$(CC) $(SRC) $(MLXFLAGS_LINUX) -o $(NAME)
	@echo '$(NAME) created w/o error flags.'

test:
	@echo $(OS)

autogit:
	git add .
	git commit -m "auto add & push"
	git push
	@echo 'git auto add & push performed.'
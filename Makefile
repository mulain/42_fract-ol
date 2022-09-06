# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:11:14 by wmardin           #+#    #+#              #
#    Updated: 2022/09/05 15:26:02 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OS = $(shell uname)

ifeq ($(OS), Linux)
MLXFLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11
DEFINEFLAGS =	-DKEY_ESC=65307 -DKEY_LEFT=65361 -DKEY_RIGHT=65363 -DKEY_UP=65362 -DKEY_DOWN=65364\
				-DKEY_W=119 -DKEY_A=97 -DKEY_S=115 -DKEY_D=100
else
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
DEFINEFLAGS = -DKEY_ESC=53 -DKEY_LEFT=123 -DKEY_RIGHT=124 -DKEY_UP=126 -DKEY_DOWN=125 -DKEY_W= -DKEY_A= -DKEY_S= -DKEY_D=
endif

NAME =	fractol
SRC =	main.c\
		setup.c\
		hooks.c\
		fractals.c mapping.c\
		put.c

%.o: %.c

LIBFT = libft/libft.a

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS) $(DEFINEFLAGS) $(LIBFT) -o $(NAME)
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
	@$(CC) $(SRC) $(MLXFLAGS) $(DEFINEFLAGS) $(LIBFT) -o $(NAME)
	@echo '$(NAME) created w/o error flags.'

test:
	@echo $(OS)

git:
	git add .
	git commit -m "auto add & push"
	git push
	@echo 'git auto add & push performed.'
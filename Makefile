# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:11:14 by wmardin           #+#    #+#              #
#    Updated: 2022/09/09 15:29:32 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OS = $(shell uname)

ifeq ($(OS), Linux)
MLXFLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11

DEFINEFLAGS =	-DKEY_ESC=65307 -DKEY_LEFT=65361 -DKEY_RIGHT=65363 -DKEY_UP=65362 -DKEY_DOWN=65364\
				-DKEY_W=119 -DKEY_A=97 -DKEY_S=115 -DKEY_D=100\
				-DKEY_I=105\
				-DKEY_C=99\
				-DMOUSE_LEFT=1 -DMOUSE_RIGHT=3 -DMOUSE_SCR_UP=4 -DMOUSE_SCR_DOWN=5
else
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
DEFINEFLAGS = 	-DKEY_ESC=53 -DKEY_LEFT=123 -DKEY_RIGHT=124 -DKEY_UP=126 -DKEY_DOWN=125\
				-DKEY_W=13 -DKEY_A= -DKEY_S=1 -DKEY_D=2\
				-DKEY_I=34\
				-DKEY_C=8\
				-DMOUSE_LEFT=1 -DMOUSE_RIGHT=2 -DMOUSE_SCR_UP=5 -DMOUSE_SCR_DOWN=4
endif

NAME =	fractol
SRC =	main.c\
		inputparsing.c\
		setup_1.c setup_2.c setup_3.c\
		calculation.c\
		draw.c\
		inside_set_1.c inside_set_2.c\
		hooks.c hook_nav.c hook_mod.c\
		fractals_1.c fractals_2.c

BLUE = \033[94m
COLOR_END = \033[0m

%.o: %.c

LIBFT = libft/libft.a

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS) $(DEFINEFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)$(NAME) created."

$(LIBFT):
	@make --no-print-directory -C ./libft

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "$(BLUE)clean performed."

fclean: clean
	@$(RM) $(NAME) $(LIBFT) a.out
	@echo "$(BLUE)fclean performed."

re: fclean all

noflag:
	@$(CC) $(SRC) $(MLXFLAGS) $(DEFINEFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)$(NAME) created w/o error flags."

test:
	@echo $(OS)

git:
	git add .
	git commit -m "auto add & push"
	git push
	@echo "$(BLUE)git auto add & push performed."
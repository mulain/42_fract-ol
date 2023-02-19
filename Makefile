# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:11:14 by wmardin           #+#    #+#              #
#    Updated: 2023/02/19 16:49:02 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	gcc
RM		=	rm -rf
CFLAGS	=	-O3 -Iincl
EFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	$(LIBFT) $(MLXFLAGS)
LIBFT	= 	libft/libft.a

ifeq ($(shell uname), Linux)
	OS			=	Linux
	MLX			=	mlx/mlx_linux/libmlx.a
	MLXFLAGS	=	$(MLX) -L/usr/lib -lXext -lX11
	MLXCOMPILE	=	@make -C mlx/mlx_linux/
	DEFINEFLAGS =	-DKEY_ESC=65307 -DKEY_LEFT=65361 -DKEY_RIGHT=65363 -DKEY_UP=65362 -DKEY_DOWN=65364\
					-DKEY_W=119 -DKEY_A=97 -DKEY_S=115 -DKEY_D=100\
					-DKEY_I=105 -DKEY_O=111\
					-DKEY_C=99\
					-DMOUSE_LEFT=1 -DMOUSE_RIGHT=3 -DMOUSE_MIDDLE=2 -DMOUSE_SCR_UP=4 -DMOUSE_SCR_DOWN=5
else
	OS			=	Mac
	MLX			=	mlx/mlx_mac/libmlx.a
	MLXFLAGS	=	$(MLX) -framework OpenGL -framework AppKit
	MLXCOMPILE	=	@make -C mlx/mlx_mac/
	DEFINEFLAGS = 	-DKEY_ESC=53 -DKEY_LEFT=123 -DKEY_RIGHT=124 -DKEY_UP=126 -DKEY_DOWN=125\
					-DKEY_W=13 -DKEY_A= -DKEY_S=1 -DKEY_D=2\
					-DKEY_I=34 -DKEY_O=31\
					-DKEY_C=8\
					-DMOUSE_LEFT=1 -DMOUSE_RIGHT=2 -DMOUSE_MIDDLE=3 -DMOUSE_SCR_UP=5 -DMOUSE_SCR_DOWN=4
endif

SRC		=	main.c\
			inputparsing.c\
			setup_1.c setup_2.c setup_3.c setup_4.c\
			calculation.c\
			draw.c\
			inside_set_1.c inside_set_2.c\
			outside_set_1.c\
			hooks.c hook_nav.c hook_mod.c\
			fractals_1.c fractals_2.c fractals_save.c

BLUE		=	\033[94m
COLOR_END	=	\033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX)
	@echo "$(BLUE)Compiling $(NAME) with $(OS)-flags.$(RESET)"
	@$(CC) $(CFLAGS) $(EFLAGS) $(SRC) $(DEFINEFLAGS) -o $(NAME) $(LFLAGS)
	@echo "$(BLUE)$(NAME) created."

$(LIBFT):
	@make --no-print-directory -C ./libft

$(MLX):
	@echo "$(BLUE)Compiling mlx with $(OS)-flags.$(RESET)"
	$(MLXCOMPILE)

%.o: %.c

clean:
	@$(RM) $(OBJ)
	@echo "$(BLUE)clean performed."

fclean: clean
	@$(RM) $(NAME) $(LIBFT)
	@echo "$(BLUE)fclean performed."

re: fclean all

git:
	git add .
	git commit -m "auto add & push"
	git push
	@echo "$(BLUE)git auto add & push performed.$(RESET)"

mgit:
	git add .
	@read -p "Enter the commit message: " msg;\
	git commit -m "$$msg"
	git push
	@echo "$(BLUE)git auto add & push with message performed.$(RESET)"
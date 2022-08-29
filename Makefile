# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:11:14 by wmardin           #+#    #+#              #
#    Updated: 2022/08/29 12:04:01 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS_LINUX = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

NAME =	fract-ol
SRC =	main.c

%.o: %.c

LIBFT = libft/libft.a

#all:
#	gcc $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o fractol

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS_LINUX) -o $(NAME)
	@echo '$(NAME) created.'


#$(NAME): $(LIBFT) $(NAME2)
#	@$(CC)  $(SRC) $(LIBFT) -o $(NAME)

#$(LIBFT):
#	@make --no-print-directory -C ./libft

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo 'clean performed.'

fclean: clean
	@$(RM) $(NAME) $(LIBFT) $(NAME2) a.out
	@echo 'fclean performed.'

re: fclean all

noflag:
	@$(CC) $(SRC) $(MLXFLAGS_LINUX) -o $(NAME)
	@echo '$(NAME) created w/o error flags.'

autogit:
	git add .
	git commit -m "auto add & push"
	git push
	@echo 'git auto add & push performed.'
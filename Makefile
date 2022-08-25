# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:11:14 by wmardin           #+#    #+#              #
#    Updated: 2022/08/24 18:05:11 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

%.o: %.c

all:
	gcc $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o fractol
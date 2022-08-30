# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 13:39:51 by wmardin           #+#    #+#              #
#    Updated: 2022/08/30 10:09:32 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
AR = ar rcs
NAME = libft.a

PATH_ft_is = src/ft_is
PATH_ft_list = src/ft_list
PATH_ft_mem = src/ft_mem
PATH_ft_put = src/ft_put
PATH_ft_string = src/ft_string
PATH_ft_gnl = src/ft_gnl
PATH_ft_printf = src/ft_printf

SRC =	$(PATH_ft_is)/ft_isalnum.c\
		$(PATH_ft_is)/ft_isalpha.c\
		$(PATH_ft_is)/ft_isascii.c\
		$(PATH_ft_is)/ft_isdigit.c\
		$(PATH_ft_is)/ft_isnumberformat.c\
		$(PATH_ft_is)/ft_isprint.c\
		$(PATH_ft_list)/ft_lstadd_back.c\
		$(PATH_ft_list)/ft_lstadd_front.c\
		$(PATH_ft_list)/ft_lstclear.c\
		$(PATH_ft_list)/ft_lstdelone.c\
		$(PATH_ft_list)/ft_lstiter.c\
		$(PATH_ft_list)/ft_lstlast.c\
		$(PATH_ft_list)/ft_lstmap.c\
		$(PATH_ft_list)/ft_lstnew.c\
		$(PATH_ft_list)/ft_lstsize.c\
		$(PATH_ft_mem)/ft_bzero.c\
		$(PATH_ft_mem)/ft_calloc.c\
		$(PATH_ft_mem)/ft_memchr.c\
		$(PATH_ft_mem)/ft_memcmp.c\
		$(PATH_ft_mem)/ft_memcpy.c\
		$(PATH_ft_mem)/ft_memmove.c\
		$(PATH_ft_mem)/ft_memset.c\
		$(PATH_ft_put)/ft_putchar_fd.c\
		$(PATH_ft_put)/ft_putendl_fd.c\
		$(PATH_ft_put)/ft_putnbr_fd.c\
		$(PATH_ft_put)/ft_putstr_fd.c\
		$(PATH_ft_string)/ft_atoi.c\
		$(PATH_ft_string)/ft_itoa.c\
		$(PATH_ft_string)/ft_split.c\
		$(PATH_ft_string)/ft_strchr.c\
		$(PATH_ft_string)/ft_strdup.c\
		$(PATH_ft_string)/ft_striteri.c\
		$(PATH_ft_string)/ft_strjoin.c\
		$(PATH_ft_string)/ft_strlcat.c\
		$(PATH_ft_string)/ft_strlcpy.c\
		$(PATH_ft_string)/ft_strlen.c\
		$(PATH_ft_string)/ft_strmapi.c\
		$(PATH_ft_string)/ft_strncmp.c\
		$(PATH_ft_string)/ft_strnstr.c\
		$(PATH_ft_string)/ft_strrchr.c\
		$(PATH_ft_string)/ft_strtrim.c\
		$(PATH_ft_string)/ft_substr.c\
		$(PATH_ft_string)/ft_tolower.c\
		$(PATH_ft_string)/ft_toupper.c\
		$(PATH_ft_gnl)/get_next_line.c\
		$(PATH_ft_gnl)/get_next_line_utils.c\
		$(PATH_ft_printf)/ft_checkformat.c\
		$(PATH_ft_printf)/ft_printchar.c\
		$(PATH_ft_printf)/ft_printdecimal.c\
		$(PATH_ft_printf)/ft_printf.c\
		$(PATH_ft_printf)/ft_printhex_lower.c\
		$(PATH_ft_printf)/ft_printhex_upper.c\
		$(PATH_ft_printf)/ft_printint.c\
		$(PATH_ft_printf)/ft_printpointer.c\
		$(PATH_ft_printf)/ft_printstring.c\
		$(PATH_ft_printf)/ft_printunsignedint.c

#VPATH = obj #obj/ft_is obj/ft_list obj/ft_mem obj/ft_put obj/ft_string obj/ft_gnl obj/ft_printf

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo '$(NAME) created.'

#$(OBJ):
#	mkdir obj -p
#	mkdir obj/ft_is obj/ft_list obj/ft_mem obj/ft_put obj/ft_string obj/ft_gnl obj/ft_printf -p
#	$(CC) $(CFLAGS) -c $< -o $@
#	mv *.o obj

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@rm -rf obj
	@echo 'clean performed.'

fclean: clean
	@$(RM) $(NAME) a.out
	@echo 'fclean performed.'

re: fclean all

autogit:
	git add .
	git commit -m "auto add & push"
	git push
	@echo 'git auto add & push performed.'

.SILENT: $(OBJ)
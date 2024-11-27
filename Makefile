# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 17:40:45 by yettalib          #+#    #+#              #
#    Updated: 2024/11/19 20:04:50 by yettalib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c	\
		char_printf.c \
		str_printf.c \
		int_dicimal_printf.c \
		hexaprintf.c \
		pointer_printf.c \
		unsigned_printf.c

OBJS = ${FILES:%.c=%.o}
CC = cc 
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)
$(NAME): ${OBJS}

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c  $< -o $@
	ar rc ${NAME} $@
	
clean:
	rm -f ${OBJS} 
	
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean
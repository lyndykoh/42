# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:49:48 by lkoh              #+#    #+#              #
#    Updated: 2024/07/26 16:45:57 by lkoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ft_printf.h

SOURCES = ft_printhex.c ft_printptr.c ft_putchar.c ft_putnbr.c \
		  ft_putstr.c ft_strlen.c ft_unsigned.c ft_printf.c ft_printhex_ptr.c

OBJECTS = $(SOURCES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o:	%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
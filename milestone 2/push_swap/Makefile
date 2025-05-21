NAME = push_swap
CC = cc
CFLAGS = -g -I$(INC_DIR) -Wall -Wextra -Werror
INC_DIR = ./inc
SOURCES = push_swap.c swap.c push.c rotate.c reverse_rotate.c sort_small.c checks.c\
		  init.c free.c helperfxn.c radix_sort.c \
		  lib/ft_strchr.c lib/ft_strdup.c lib/ft_strjoin.c lib/ft_substr.c \
		  lib/ft_strncmp.c lib/ft_putstr_fd.c lib/ft_split.c lib/ft_isdigit.c lib/ft_atol.c
OBJECTS = $(SOURCES:.c=.o) $(LIBFT:.c=.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./printf
	$(CC) $(CFLAGS)  $(OBJECTS) -L./printf -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ./printf clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

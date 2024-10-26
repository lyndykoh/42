NAME = pipex
CC = cc
CFLAGS = -g -I$(INC_DIR) -Wextra -Werror -Wextra
INC_DIR = ./inc
SOURCES = pipex.c get_next_line.c ppxclean.c ppxinitexit.c ppxhelper.c\
		  ft_strchr.c ft_strdup.c ft_strjoin.c ft_substr.c \
		  ft_strncmp.c ft_putstr_fd.c ft_split.c 
# LIBFT = ft_strchr.c ft_strdup.c ft_strjoin.c ft_substr.c ft_strncmp.c ft_putstr_fd.c ft_split.c 
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

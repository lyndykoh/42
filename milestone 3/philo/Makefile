NAME = philo
CC = cc
CFLAGS = -g -I$(INC_DIR) -Wall -Wextra -Werror # -fsanitize=thread
INC_DIR = ./inc
SOURCES = philo.c init.c free.c routine.c threads.c actions.c time.c helper.c ft_isdigit.c\
		  ft_atoi.c 
OBJECTS = $(SOURCES:.c=.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS)  $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

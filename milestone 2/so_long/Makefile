NAME = so_long
CC = cc
CFLAGS = -g -I$(INC_DIR)
INC_DIR = ./inc
SOURCES = ./src/so_long.c ./src/ft_split.c ./src/ft_strchr.c ./src/init.c ./src/cleanup.c ./src/checkmap.c
OBJECTS = $(SOURCES:.c=.o)
MLXFLAG = -Llmlx -lmlx_Linux -L/usr/lib/X11 -lXext -lX11
MLXDIR = ./lmlx

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./printf
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS)  $(OBJECTS) $(MLXFLAG) -L./printf -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ./printf clean
#	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

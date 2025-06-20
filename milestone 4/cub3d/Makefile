NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I$(INC_DIR)

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft

SOURCES = $(SRC_DIR)/cub3d.c \
          $(SRC_DIR)/init.c \
          $(SRC_DIR)/checkmap.c \
          $(SRC_DIR)/utils.c \
          ./gnl/get_next_line.c \

OBJECTS = $(SOURCES:.c=.o)
LIBFT   = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

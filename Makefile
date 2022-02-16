NAME = so_long

CC = cc

MLX = minilibx.a
MLX2 = minilibx1.a
LIBFT = ./libft/libft.a
LIB_BINARY	= -L./libft -lft

CFLAGS = -Wall -Wextra -Werror

SRC = main.c check.c check1.c draw_map.c enemy.c get_env.c key_move.c read_map.c

OBJ = $(patsubst %.c, %.o, $(SRC))

RM = rm -rf

all: $(LIBFT) ./libft/libft.a $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) $(LIB_BINARY) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	make -C ./minilibx_opengl/

$(LIBFT):
	make -C ./libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C ./minilibx_opengl/ clean
	make -C ./minilibx_mms/ clean
	make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)

NAME		= So_Long
OS			= $(shell uname -s)
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -O3
MACOS_DIR	= mlx/minilibx-macos
LINUX_DIR	= mlx/minilibx-linux
LIBFT		= libft/libft.a
LINUX_LIB	= $(LINUX_DIR)/libmlx.a
MACOS_LIB	= $(MACOS_DIR)/libmlx.a

MAPS 		= maps/map1.ber maps/map2.ber maps/map3.ber maps/map4.ber maps/map5.ber4
TEST_DIR	= maps/test_maps/
TEST		= extention no_collectable.ber no_exit.ber no_player.ber path_collectable.ber \
			  path_exit.ber permission.ber square.ber surrounded.ber surrounded_2.ber \
			  surrounded_3.ber surrounded_4.ber not_exist.ber
TEST_MAPS	= $(addprefix $(TEST_DIR), $(TEST))

RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m

ifeq ($(OS), Linux)
	OS_FLAGS = -L$(LINUX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	LIB_DIR  = $(LINUX_DIR)
	MINILIBX = $(LINUX_LIB)
else ifeq ($(OS), Darwin)
	OS_FLAGS = -L$(MACOS_DIR) -lmlx -framework OpenGL -framework AppKit -lz
	LIB_DIR  = $(MACOS_DIR)
	MINILIBX = $(MACOS_LIB)
endif

SRC_DIR = Sources/
SRCS	=	main.c \
			enemy.c \
			heart.c \
			portal.c \
			gameplay.c \
			init_mlx.c \
			init_map.c \
			get_floor.c \
			next_frame.c \
			clean_exit.c \
			show_error.c \
			clean_enemy.c \
			clean_floor.c \
			init_struct.c \
			init_images.c \
			parsing_map.c \
			clean_portal.c \
			clean_player.c \
			so_long_utils.c \
			file_to_image.c \
			player_animation.c \
			file_to_image_enemy.c \
			file_to_image_player.c \
			file_to_image_level_1.c \
			file_to_image_level_2.c \
			file_to_image_player_dash.c \
			file_to_image_portal.c

SOURCES = $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR	= Objects/
OBJS	= $(SRCS:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJS))
  
all: $(OBJ_DIR) $(NAME)

$(MINILIBX):
	$(MAKE) -C $(LIB_DIR)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJECTS)
	$(CC) $(OBJECTS) $(OS_FLAGS) -Llibft -lft -o $(NAME)
	echo "$(GREEN)$(NAME)		compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm -f $(MINILIBX)

re: fclean all

run_maps: $(NAME)
	@for level in $(MAPS); do \
		echo "Running $$level"; \
		./$(NAME) $$level; \
	done

test_maps: $(NAME)
	@for level in $(TEST_MAPS); do \
		echo "Running test $$level"; \
		./$(NAME) $$level; \
	done

.SILENT:
.PHONY: all clean fclean re

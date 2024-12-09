#
# HEADER
#
#
#
#
#
#
#
#
#
#
#
# HEADER
#

NAME 							=	cub3d
CC 								=	gcc
CFLAGS							=	-Wall -Wextra -Werror
SRC_DIR							=	src
INCLUDE_DIR						=	include
LIBFT_DIR						=	libft
GNL_DIR							=	gnl
OBJ_DIR							=	obj
MLX_DIR							=	mlx
MLX_ICLUDES						=	/usr/include
PARSIG_DIR						=	$(SRC_DIR)/parsing
MAP_2D							=	$(SRC_DIR)/map_2d
RAYCASTING						=	$(SRC_DIR)/raycasting

SRCS							=	Cub3d.c $(SRC_DIR)/error_gestion.c $(SRC_DIR)/init_structs.c \
									$(SRC_DIR)/test_utils.c \
									$(PARSIG_DIR)/start_parsing.c \
									$(PARSIG_DIR)/textures_map.c \
									$(PARSIG_DIR)/fill_map_array.c \
									$(PARSIG_DIR)/check_basics.c \
									$(PARSIG_DIR)/parsing_utils.c \
									$(PARSIG_DIR)/parsing_utils_2.c \
									$(PARSIG_DIR)/check_map.c \
									$(PARSIG_DIR)/count_file_caracters.c \
									$(MAP_2D)/start_map_2d.c \
									$(MAP_2D)/games_loop.c \
									$(MAP_2D)/draw_grid.c \
									$(MAP_2D)/render_game.c \
									$(MAP_2D)/utils_2d.c \
									$(MAP_2D)/key.c \
									$(RAYCASTING)/raycast.c \
									$(RAYCASTING)/play_3d.c \
									$(RAYCASTING)/utils_ray.c \
									$(RAYCASTING)/textures.c \
									$(RAYCASTING)/touch_wall.c \
									$(SRC_DIR)/bonus/mini_map.c

OBJS							=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS							:=	$(OBJS:$(GNL_DIR)/%/c=$(OBJ_DIR)/%.o)
LIBFT							=	$(LIBFT_DIR)/libft.a

LDFLAGS							=	-L$(LIBFT_DIR)
INCLUDES						=	-I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) \
									-I$(MLX_ICLUDES) -I$(GNL_DIR)

# Default target
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib \
	-I$(MLX_DIR) -lXext -lX11 -lm -lz $(LDFLAGS) -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

# Compile the libft library
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
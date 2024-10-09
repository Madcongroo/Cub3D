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
OBJ_DIR							=	obj
MLX_DIR							=	mlx
MLX_INCLUDES					=	/usr/include
PARSING_DIR						=	$(SRC_DIR)/parsing

SRCS							=	Cub3d.c $(SRC_DIR)/error_gestion.c  $(PARSING_DIR)/start_parsing.c \
									$(SRC_DIR)/test_utils.c $(SRC_DIR)/init_struct.c

OBJS							=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT							=	$(LIBFT_DIR)/libft.a
LDFLAGS							=	-L$(LIBFT_DIR)
INCLUDES						=	-I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) \
									-I$(MLX_INCLUDES)

# Default target
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib \
	-I$(MLX_DIR) -lXext -lX11 -lm -lz $(LDFLAGS) -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: %.c
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


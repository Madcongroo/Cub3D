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

NAME = cub3d

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
OBJ_DIR = obj
MLX_DIR = mlx
MLX_ICLUDES = /usr/include
PARSING_DIR = $(SRC_DIR)/parsing

# Fichiers sources
SRCS = Cub3d.c \
       $(SRC_DIR)/error_gestion.c \
       $(SRC_DIR)/test_utils.c \
	   $(SRC_DIR)/init_structs.c \
       $(PARSING_DIR)/start_parsing.c \
       $(PARSING_DIR)/textures_map.c

# Fichiers objets
OBJS = $(OBJ_DIR)/Cub3d.o \
       $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.c,$(SRCS))) \
       $(patsubst $(PARSING_DIR)/%.c,$(OBJ_DIR)/parsing/%.o,$(filter $(PARSING_DIR)/%.c,$(SRCS)))

# Librairies
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

# Flags pour l'édition de liens (linker)
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

# Inclusions des headers
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(MLX_ICLUDES)

# Cible par défaut
all: $(NAME)

# Lier l'exécutable final
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Règle pour Cub3d.o à la racine
$(OBJ_DIR)/Cub3d.o: Cub3d.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

# Compilation des fichiers objets dans le répertoire obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(OBJ_DIR)/parsing/%.o: $(PARSING_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation de la MinilibX
$(MLX):
	make -C $(MLX_DIR)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

# Nettoyage complet (objets et exécutable)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
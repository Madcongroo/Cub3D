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
#
#
#
#

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ./src/Cub3d.c
OBJ = $(SRC:.c=.o)

%.o: $.c
	@echo "\033[32mcompiling $<...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[34mFiles compiled successfully!\033[0m"

all: $(NAME)

clean:
	@echo "\033[32mCleaning up object files...\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[32mCleaning up object files and executable...\033[0m"
	@rm -rf $(NAME)

re: clean fclean all
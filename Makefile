NAME = pipex
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes

SRC = main.c \
	parsing.c \
	exec.c \
	run.c \
	path.c \
	split_cmd.c \
	utils_exec.c \
	utils_buffer.c \
	utils_path.c \
	utils_path2.c \
	utils_run.c \
	utils_split.c \
	utils_token.c \
	utils_token2.c \
	utils.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INCLUDES_DIR)

all: $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(MAKE) loading
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR)/pipex.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🗑️ Removing object files from pipex..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) --silent

fclean: clean
	@echo "🧺 Full clean: removing binary and libft archive..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent

re: fclean all

.PHONY: all clean fclean re loading

loading:
	@echo "✅ Compilation terminée avec succès !"
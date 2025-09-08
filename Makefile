NAME = pipex

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c \
  parsing.c \
  exec.c \
  run.c \
  path.c\
  split_cmd.c \
  utils_buffer.c \
  utils_path.c \
  utils_split.c \
  utils_token.c \
  utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(MAKE) loading
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@echo "🗑️ Removing object files from pipex..."
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR) --silent

fclean: clean
	@echo "🧺 Full clean: removing binary and libft archive..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent

re: fclean all

.PHONY: all clean fclean re

loading:
	@echo "✅ Compilation terminée avec succès !"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
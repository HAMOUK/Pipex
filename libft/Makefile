NAME = libft.a

CFILES = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\

BONUSFILES = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

PFTFILES = ft_printf/ft_printf.c\
	ft_printf/ft_char.c\
	ft_printf/ft_string.c\
	ft_printf/ft_int.c\
	ft_printf/ft_unsigned.c\
	ft_printf/ft_pointer.c\
	ft_printf/ft_hexamin.c\
	ft_printf/ft_hexamaj.c\
	ft_printf/ft_hexalen.c\
	ft_printf/ft_putchar_fd.c\
	ft_printf/ft_putnbr_fd.c\
	ft_printf/ft_putstr_fd.c\
	ft_printf/ft_strlen.c

OBJS := $(CFILES:.c=.o)
BONUS_OBJS = $(BONUSFILES:.c=.o)
PFT_OBJS = $(PFTFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEAD = includes/

all: ${NAME}

${NAME} : ${OBJS} ${PFT_OBJS}
	@ar rcs ${NAME} ${OBJS} ${PFT_OBJS}

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(HEAD) -Ift_printf -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(PFT_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean all re bonus
NAME = push_swap
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRC = push_swap.c push_swap2.c push_swap3.c push_swap4.c push_swap_parsing.c
SRCS = $(addprefix $(LIBFT_DIR),$(SRC))
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT_DIR)$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
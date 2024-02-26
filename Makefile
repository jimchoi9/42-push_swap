NAME = push_swap
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c push_swap_stack.c push_swap_instructions.c push_swap_utils.c push_swap_parsing.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
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
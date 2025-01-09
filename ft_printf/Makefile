CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
ARFLAGS = rcs
SRCS = ft_handle_putchar.c \
	ft_handle_string.c \
	ft_print_hex.c \
	ft_printnbr.c \
	ft_printf.c \
	ft_handle_unsigned.c \
	ft_handle_ptr.c

OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	ar $(ARFLAGS) $@ $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

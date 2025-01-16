CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME1 = server
NAME2 = client

SERVER_SRC = server.c
CLIENT_SRC = client.c
OBJ = obj
LIBFT = ./libft

SERVER_OBJ = $(OBJ)/$(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(OBJ)/$(CLIENT_SRC:.c=.o)

all: $(NAME1) $(NAME2)

$(OBJ)/%.o: %.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(PRINTF)/libftprintf.a:
	@make -C $(PRINTF)

$(NAME1): $(SERVER_OBJ) $(LIBFT)/libft.a 
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT) -lft  -o $(NAME1)

$(NAME2): $(CLIENT_OBJ) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT) -lft  -o $(NAME2)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

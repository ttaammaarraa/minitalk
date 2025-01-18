CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME1 = server
NAME2 = client


NAME1_BONUS = server_bonus
NAME2_BONUS = client_bonus

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_SRCB = server_bonus.c
CLIENT_SRCB = client_bonus.c

OBJ = obj
LIBFT = ./libft

SERVER_OBJ = $(OBJ)/$(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(OBJ)/$(CLIENT_SRC:.c=.o)

SERVER_OBJB = $(OBJ)/$(SERVER_SRCB:.c=.o)
CLIENT_OBJB = $(OBJ)/$(CLIENT_SRCB:.c=.o)

all: $(NAME1) $(NAME2)

$(OBJ)/%.o: %.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	@make -C $(LIBFT)


$(NAME1): $(SERVER_OBJ) $(LIBFT)/libft.a 
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT) -lft  -o $(NAME1)

$(NAME2): $(CLIENT_OBJ) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT) -lft  -o $(NAME2)

bonus : $(NAME1_BONUS) $(NAME2_BONUS)

$(NAME1_BONUS): $(SERVER_OBJB) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(SERVER_OBJB) -L$(LIBFT) -lft  -o $(NAME1_BONUS)

$(NAME2_BONUS): $(CLIENT_OBJB) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(CLIENT_OBJB) -L$(LIBFT) -lft  -o $(NAME2_BONUS)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@rm -f $(NAME1_BONUS)
	@rm -f $(NAME2_BONUS)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus 
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS_SRCS = server_bonus.c
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS = client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft
$(SERVER): $(SERVER_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client
$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFT) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) -o client_bonus
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
clean:
		$(MAKE) clean -C ./libft
		rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
		rm -f $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(SERVER) $(CLIENT)
		rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
re: fclean all
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SERVER = server
CLIENT = client

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft
$(SERVER): $(SERVER_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client

clean:
		$(MAKE) clean -C ./libft
		rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(SERVER) $(CLIENT)
re: fclean all
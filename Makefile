#Client and server
CLIENT_SRC = client.c
CLIENT = client
SERVER_SRC = server.c
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 

LIB = libft.a
LIB_PATH = ./Libft

all: LIBFT
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIB) -o $(CLIENT)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIB) -o $(SERVER)

LIBFT:
	@echo Making libft.a...
	@make --silent -C $(LIB_PATH)
	@mv $(LIB_PATH)/$(LIB) .

clean:
	make clean -C $(LIB_PATH)
	rm -rf $(LIB)

fclean: clean
	rm -rf client server

re: fclean all
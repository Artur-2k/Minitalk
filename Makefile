CLIENT_SRC = client.c
CLIENT = client
SERVER_SRC = server.c
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIB = libft.a
LIB_PATH = ./Libft
LIB_TARGET = $(LIB_PATH)/$(LIB)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIB) -o $(CLIENT)

$(SERVER): $(SERVER_SRC) $(LIB)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIB) -o $(SERVER)

$(LIB):
	echo Making libft.a...
	make --silent -C $(LIB_PATH)
	mv $(LIB_TARGET) .

clean:
	make clean -C $(LIB_PATH)
	rm -f $(LIB)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

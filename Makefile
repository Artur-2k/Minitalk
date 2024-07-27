CLIENT_SRC = client.c
CLIENT = client
SERVER_SRC = server.c
SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LIB = libft.a
LIB_PATH = ./Libft
LIB_TARGET = $(LIB_PATH)/$(LIB)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(LIB) minitalk.h
	$(CC) $(CFLAGS) $< $(LIB) -o $@

$(SERVER): $(SERVER_SRC) $(LIB) minitalk.h
	$(CC) $(CFLAGS) $< $(LIB) -o $@

$(LIB): $(LIB_TARGET)
	cp $< $@

$(LIB_TARGET):
	@echo "Making libft.a..."
	@$(MAKE) -C $(LIB_PATH)

clean:
	@$(MAKE) -C $(LIB_PATH) clean
	@rm -f $(LIB)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
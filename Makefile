
PRINTF=libftprintf.a


CLIENT_FILES = client.c common.c utils.c
CLIENT_SRC = $(addprefix $(SRC_DIR), $(CLIENT_FILES))
CLIENT_ARTIFACT = client
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_FILES = server.c common.c utils.c
SERVER_SRC = $(addprefix $(SRC_DIR), $(SERVER_FILES))
SERVER_ARTIFACT = server
SERVER_OBJ = $(SERVER_SRC:.c=.o)

SRC_DIR= ./src/
INCLUDE_DIR= ./include/

CC = gcc
CLAGS = -wall -extra -werror -I$(INCLUDE_DIR)

RM = rm -f

all : $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)


$(CLIENT_ARTIFACT) : $(CLIENT_SRC)
	@make -C ft_printf
	$(CC) $(CFLAGS) ft_printf/$(PRINTF) -o $@ $^

$(SERVER_ARTIFACT) : $(SERVER_SRC)
	$(CC) $(CFLAGS) ft_printf/$(PRINTF) -o $@ $^

clean: 
	$(RM) $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)

fclean:clean
	@make fclean -C ft_printf
	$(RM) $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)

re: fclean all

.PHONY: all clean re fclean
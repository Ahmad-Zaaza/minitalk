PRINTF=libftprintf.a

CLIENT_FILES = client.c utils.c
CLIENT_SRC = $(addprefix $(SRC_DIR), $(CLIENT_FILES))
CLIENT_ARTIFACT = client
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_FILES = server.c utils.c
SERVER_SRC = $(addprefix $(SRC_DIR), $(SERVER_FILES))
SERVER_ARTIFACT = server
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_B_FILES = client_bonus.c utils.c
CLIENT_B_SRC = $(addprefix $(SRC_DIR), $(CLIENT_B_FILES))
CLIENT_B_ARTIFACT = client_bonus
CLIENT_B_OBJ = $(CLIENT_B_SRC:.c=.o)

SERVER_B_FILES = server_bonus.c utils.c
SERVER_B_SRC = $(addprefix $(SRC_DIR), $(SERVER_B_FILES))
SERVER_B_ARTIFACT = server_bonus
SERVER_B_OBJ = $(SERVER_B_SRC:.c=.o)

SRC_DIR= ./src/
INCLUDE_DIR= ./include/

CC = gcc
CLAGS = -wall -extra -werror -I$(INCLUDE_DIR)

RM = rm -f

all : $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT) $(CLIENT_B_ARTIFACT) $(SERVER_B_ARTIFACT)


$(CLIENT_ARTIFACT) : $(CLIENT_SRC)
	@make -C ft_printf
	$(CC) $(CFLAGS) ft_printf/$(PRINTF) -o $@ $^

$(SERVER_ARTIFACT) : $(SERVER_SRC)
	$(CC) $(CFLAGS) ft_printf/$(PRINTF) -o $@ $^

$(CLIENT_B_ARTIFACT) : $(CLIENT_B_SRC)
	@make -C ft_printf
	$(CC) $(CFLAGS) ft_printf/$(PRINTF) -o $@ $^

$(SERVER_B_ARTIFACT) : $(SERVER_B_SRC)
	$(CC) $(CFLAGS) ft_printf/$(PRINTF) -o $@ $^


bonus: $(CLIENT_B_ARTIFACT) $(SERVER_B_ARTIFACT)


clean: 
	$(RM) $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)
	$(RM) $(CLIENT_B_ARTIFACT) $(SERVER_B_ARTIFACT)

fclean:clean
	@make fclean -C ft_printf
	$(RM) $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)
	$(RM) $(CLIENT_B_ARTIFACT) $(SERVER_B_ARTIFACT)

re: fclean all

.PHONY: all clean re fclean bonus
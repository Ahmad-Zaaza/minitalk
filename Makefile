# OBJ = $(SRCS:.c=.o)


CLIENT_FILES = client.c
CLIENT_SRC = $(addprefix $(SRC_DIR), $(CLIENT_FILES))
CLIENT_ARTIFACT = client

SERVER_FILES = server.c
SERVER_SRC = $(addprefix $(SRC_DIR), $(SERVER_FILES))
SERVER_ARTIFACT = server

SRC_DIR= ./src/
INCLUDE_DIR= ./include/

CC = gcc
CLAGS = -wall -extra -werror -I$(INCLUDE_DIR)

RM = rm -f

all : $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)


$(CLIENT_ARTIFACT) : $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_ARTIFACT) : $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $@ $^


clean: 
	$(RM) $(CLIENT_ARTIFACT) $(SERVER_ARTIFACT)

.PHONY: all clean
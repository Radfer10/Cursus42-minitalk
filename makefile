# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 18:50:09 by rde-migu          #+#    #+#              #
#    Updated: 2024/06/26 20:33:46 by rde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME := client
SERVER_NAME := server

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SOURCE_CLIENT := src/client.c
SOURCE_SERVER := src/server.c

OBJECTS_CLIENT := $(SOURCE_CLIENT:.c=.o)
OBJECTS_SERVER := $(SOURCE_SERVER:.c=.o)

LIBFT := libft/libft.a
INCLUDES := -Iincludes -Ilibft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(OBJECTS_CLIENT)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT) $(OBJECTS_SERVER)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) $(LIBFT) -o $(SERVER_NAME)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJECTS_CLIENT) $(OBJECTS_SERVER)
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
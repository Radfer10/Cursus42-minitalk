# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 18:50:09 by rde-migu          #+#    #+#              #
#    Updated: 2024/07/03 23:29:51 by rde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Names
CLIENT_NAME := client
SERVER_NAME := server
CLIENT_NAME_BONUS := client_bonus
SERVER_NAME_BONUS := server_bonus

# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Source Files
SOURCE_CLIENT := src/client.c
SOURCE_SERVER := src/server.c
SOURCE_CLIENT_BONUS := src/client_bonus.c
SOURCE_SERVER_BONUS := src/server_bonus.c

# Object Files
OBJECTS_CLIENT := $(SOURCE_CLIENT:.c=.o)
OBJECTS_SERVER := $(SOURCE_SERVER:.c=.o)
OBJECTS_CLIENT_BONUS := $(SOURCE_CLIENT_BONUS:.c=.o)
OBJECTS_SERVER_BONUS := $(SOURCE_SERVER_BONUS:.c=.o)

# Includes and Library
LIBFT := libft/libft.a
INCLUDES := -Iincludes -Ilibft

# Rules for object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Default target
all: $(CLIENT_NAME) $(SERVER_NAME)

# Client binary
$(CLIENT_NAME): $(LIBFT) $(OBJECTS_CLIENT)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) $(LIBFT) -o $(CLIENT_NAME)

# Server binary
$(SERVER_NAME): $(LIBFT) $(OBJECTS_SERVER)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) $(LIBFT) -o $(SERVER_NAME)

# Bonus binaries
bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): $(LIBFT) $(OBJECTS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS): $(LIBFT) $(OBJECTS_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER_BONUS) $(LIBFT) -o $(SERVER_NAME_BONUS)

# Compile libft
$(LIBFT):
	make -C libft

# Clean up object files
clean:
	$(RM) $(OBJECTS_CLIENT) $(OBJECTS_SERVER) $(OBJECTS_CLIENT_BONUS) $(OBJECTS_SERVER_BONUS)
	make clean -C libft

# Clean up all files
fclean: clean
	make fclean -C libft
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

# Rebuild all
re: fclean all

.PHONY: all bonus clean fclean re

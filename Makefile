# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 13:34:02 by vafavard          #+#    #+#              #
#    Updated: 2025/10/28 13:37:51 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_PATH = sources/

SRC_FILES = checkMap.c free.c ft_util_2.c get_next_line_utils.c get_next_line.c init.c \
			main.c utils.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(patsubst %.c,%.o,$(SRC))
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)


%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

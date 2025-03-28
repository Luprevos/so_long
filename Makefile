# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 19:16:50 by luprevos          #+#    #+#              #
#    Updated: 2025/03/29 00:09:12 by luprevos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES = -I./minilibx-linux -I.

SRC = get_next_line/get_next_line.c \
	  get_next_line/get_next_line_utils.c \
	  get_next_line/main.c \
      flood_fill.c\
      parsing.c\
      parsingmap.c\
      utils.c\
	  main.c\
	  windowparams.c\
	  texture.c\
	  texture2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
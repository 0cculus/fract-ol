# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 16:39:21 by brheaume          #+#    #+#              #
#    Updated: 2023/02/21 13:20:43 by brheaume         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  draw.c \
	  utils.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBS = -I include -lglfw -L "/USERS/${USER}/homebrew/opt/glfw/lib/"

LIBDIR = ./libft
LIBFT = libft.a

MLXDIR = ./MLX42

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LIBDIR)/$(LIBFT) $(MLXDIR)/libmlx42.a $(LIBS) -o $(NAME)

clean: 
	rm -f $(LIBDIR)/*.o
	rm -f  $(OBJ)

fclean: clean
	rm -f $(NAME)

libft:
	$(MAKE) -C $(LIBDIR)/

.PHONY: all libft

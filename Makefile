#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybokina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 12:12:47 by ybokina           #+#    #+#              #
#    Updated: 2018/08/25 17:56:25 by ybokina          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := ft_select

FLAGS := -Wall -Wextra -Werror

SOURCES := main.c ft_error.c

OBJ := $(SOURCES:.c=.o)

HEADER := ft_select.h

LIBFT := $(LIBFT_DIR)libft.a

LIBFT_DIR := libft/

HEADER_FLAGS := -I. -I $(LIBFT_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L $(LIBFT_DIR) -ltermcap

%.o: %.c ft_select.h
	$(CC) -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

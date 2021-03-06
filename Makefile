#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybokina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 12:12:47 by ybokina           #+#    #+#              #
#    Updated: 2018/09/13 14:30:23 by ybokina          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := ft_select

FLAGS := -Wall -Wextra -Werror

SOURCES := main.c ft_error_1.c ft_error_2.c ft_actions.c ft_signal.c ft_keyboard.c ft_nodes.c ft_print.c ft_arrow_1.c ft_keys.c ft_korz.c ft_arrow_2.c ft_print_elem.c ft_arrow_3.c

OBJ := $(SOURCES:.c=.o)

HEADER := ft_select.h

LIBFT := $(LIBFT_DIR)libft.a

LIBFT_DIR := libft/

HEADER_FLAGS := -I. -I $(LIBFT_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L $(LIBFT_DIR) -ltermcap
	@echo "\033[48;5;7m\033[31m\033[5mDone: ./ft_select is created."

%.o: %.c ft_select.h
	@$(CC) -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

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

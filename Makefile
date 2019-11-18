# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpole <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 10:08:31 by bpole             #+#    #+#              #
#    Updated: 2019/11/18 21:46:19 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap

LIB_DIR = ./ft_printf/
LIBFT = $(LIB_DIR)libftprintf.a

SRC_C = ./checker.c ./commands.c ./util.c ./commands_next.c \
        ./creat_stack.c ./free_or_del.c
SRC_P = ./push_swap.c ./commands.c ./solver_algo.c ./util.c \
        ./get_commands.c ./commands_next.c ./do_commands.c \
        ./creat_stack.c ./separate.c ./free_or_del.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_P = $(SRC_P:.c=.o)

INCLUDE = ./push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME_C) $(NAME_P)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME_C): $(OBJ_C)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) $(LIBFT)

$(NAME_P): $(OBJ_P)
	$(CC) $(FLAGS) -o $(NAME_P) $(OBJ_P) $(LIBFT)

clean:
	rm -rf $(OBJ_C) $(OBJ_P)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME_C) $(NAME_P)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

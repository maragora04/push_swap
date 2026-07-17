# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 17:49:02 by andmigue          #+#    #+#              #
#    Updated: 2026/07/17 12:23:11 by andmigue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f

SRC = \
	algorithms/bubble_sort.c \
	algorithms/chunk.c \
	algorithms/radix.c \
	operations/operations_push.c \
	operations/operations_rotate.c \
	operations/operations_rrotate.c \
	operations/operations.c \
	parsing/bench.c \
	parsing/disorder.c \
	parsing/parser.c \
	parsing/parser_utils.c \
	utils/ft_atoi_safe.c \
	utils/ft_split.c \
	utils/utils.c \
	utils/stack_utils.c \
	sort/sort_helpers.c \
	sort/sorting.c \
	sort/sorting2.c \
	main.c \

OBJS = $(SRC:.c=.o)

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I. -I$(PRINTF_DIR)

all: $(NAME)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
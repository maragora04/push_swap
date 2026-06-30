# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 17:49:02 by andmigue          #+#    #+#              #
#    Updated: 2026/06/30 17:17:24 by andmigue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f

SRC = ft_split.c more_utils.c operations.c parser.c stack_utils.c \
      bubble_sort.c ft_atoi_safe.c main.c operations_rotate.c \
	  operations_rrotate.c operations_push.c radix.c chunk.c disorder.c \

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
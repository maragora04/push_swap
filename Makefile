# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 17:49:02 by andmigue          #+#    #+#              #
#    Updated: 2026/06/16 16:26:57 by andmigue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f

SRC = ft_split.c more_utils.c operations.c parser.c stack_utils.c \
      bubble_sort.c ft_atoi_safe.c main.c operations_rotate.c \
	  operations_rrotate.c operations_push.c radix.c chunk.c\

OBJS = $(SRC:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
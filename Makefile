# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makamins <makamins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 19:06:43 by makamins          #+#    #+#              #
#    Updated: 2024/11/25 14:36:09 by makamins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror 
SRC = ft_printf.c ft_putstr.c ft_hundle_pointer.c ft_putchar.c ft_putnbr.c \
	ft_putnbr_hex.c ft_putnbr_unsigned.c
CC = cc

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
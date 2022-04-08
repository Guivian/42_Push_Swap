# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 00:45:07 by lbarbosa          #+#    #+#              #
#    Updated: 2022/04/08 17:00:40 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -o

C_SRC = check_error.c init_stack.c main.c small_algorithm.c big_algorithm.c stack_pushtop.c stack_reverserotate.c stack_rotate.c stack_swap_top2.c

all: $(NAME)

$(NAME): $(C_SRC)
	@cd ft_printf && make && cd ..
	@$(CC) $(CFLAGS) $(NAME) push_swap.h $(C_SRC) ft_printf/libftprintf.a

clean:
	@cd ft_printf && make clean && cd ..

fclean: clean
	@rm -rf $(NAME)
	@cd ft_printf && make fclean && cd ..

re: fclean all

.PHONY: all clean fclean re
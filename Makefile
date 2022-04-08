# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 00:45:07 by lbarbosa          #+#    #+#              #
#    Updated: 2022/04/06 19:38:37 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -o

C_SRC = check_error.c init_stack.c main.c one_to_five_algorithm.c one_to_five_hundred_algorithm.c stack_pushtop.c stack_reverserotate.c stack_rotate.c stack_swap_top2.c

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
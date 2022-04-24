/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:16:01 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/24 20:04:50 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				n;
	int				simp_n;
	struct s_stack	*next;
}	t_stack;

//big_algorithm.c
void	big_numbers1(t_stack **stack_a, t_stack **stack_b, int argc);

//check_error.c
int		check_error(int argc, char **argv);

//init_stack.c
void	init_stack(t_stack **stack_a, int argc, char **argv);

//small_algorithm.c
void	choose_algorithm(int argc, t_stack **stack_a);

//stack_pushtop.c
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

//stack_reverserotate.c
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

//stack_rotate.c
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

//stack_swap_top2.c
void	swap_top2_a(t_stack **stack_a);
void	swap_top2_b(t_stack **stack_b);
void	swap_top2_ab(t_stack **stack_a, t_stack **stack_b);

//stack_utils.c
t_stack	*stacknew(int n);
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack_a, t_stack *new);
void	printf_list(t_stack *stack_a);
void	ft_deallocate(t_stack **stack_a);

#endif

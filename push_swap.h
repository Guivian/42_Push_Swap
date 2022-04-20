/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:16:01 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/20 18:22:54 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

int		check_error(int argc, char **argv);
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack_a, t_stack *new);
t_stack	*stack_last(t_stack *stack);
void	printf_list(t_stack *stack_a);
void	swap_top2_a(t_stack **stack_a);
void	swap_top2_b(t_stack **stack_b);
void	swap_top2_ab(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	choose_algorithm(int argc, t_stack **stack_a, int *chunk);
void	big_numbers1(t_stack **stack_a, t_stack **stack_b, int argc, int *ar);
t_stack	*stacknew(int n);

#endif

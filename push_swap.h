/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:16:01 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/18 18:56:52 by lbarbosa         ###   ########.fr       */
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
void	init_stack(t_stack **stack_a, int argc, char **argv);
void	stackadd_front(t_stack **stack_a, t_stack *new);
void	printf_list(t_stack *stack_a);
void	switchtop(t_stack **stack);
void	switch_a(t_stack **stack_a);
void	switch_b(t_stack **stack_b);
void	switch_ab(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*stacknew(int n);

#endif

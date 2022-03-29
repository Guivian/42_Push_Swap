/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_top2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:05 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/17 19:27:08 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top2(t_stack **stack)
{
	int	temp;

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

void	swap_top2_a(t_stack **stack_a)
{
	swap_top2(stack_a);
	write(1, "sa\n", 3);
}

void	swap_top2_b(t_stack **stack_b)
{
	swap_top2(stack_b);
	write(1, "sb\n", 3);
}

void	swap_top2_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap_top2(stack_a);
	swap_top2(stack_b);
	write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_switchtop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:05 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/17 19:27:08 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switchtop(t_stack **stack)
{
	int	temp;

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

void	switch_a(t_stack **stack_a)
{
	switchtop(stack_a);
	write(1, "sa\n", 3);
}

void	switch_b(t_stack **stack_b)
{
	switchtop(stack_b);
	write(1, "sb\n", 3);
}

void	switch_ab(t_stack **stack_a, t_stack **stack_b)
{
	switchtop(stack_a);
	switchtop(stack_b);
	write(1, "ss\n", 3);
}

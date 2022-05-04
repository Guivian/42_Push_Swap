/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushtop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:40:00 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/02 18:11:03 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_headnode(t_stack **stack);

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = stacknew((*stack_a)->n, (*stack_a)->simp_n);
		delete_headnode(stack_a);
	}
	else
	{
		temp = stacknew((*stack_a)->n, (*stack_a)->simp_n);
		stackadd_front(stack_b, temp);
		delete_headnode(stack_a);
	}
	write(1, "pb\n", 3);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = NULL;
	if (*stack_b == NULL)
		return ;
	temp = stacknew((*stack_b)->n, (*stack_b)->simp_n);
	stackadd_front(stack_a, temp);
	delete_headnode(stack_b);
	write(1, "pa\n", 3);
}

void	delete_headnode(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp != NULL)
		*stack = temp->next;
	free(temp);
	return ;
}

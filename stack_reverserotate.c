/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverserotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:20:07 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/20 21:58:20 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	int		store;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	store = temp->n;
	temp = NULL;
	temp = stacknew(store);
	stackadd_front(stack, temp);
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	free(last);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

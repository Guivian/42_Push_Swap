/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:36:50 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/07 18:52:26 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int n)
{
	t_stack *nbr;
	t_stack	*temp;

	nbr = NULL;
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->n = n;
	temp->next = NULL;
	nbr = temp;
	return (nbr);
}

t_stack *stacklast(t_stack *stack)
{
	t_stack *temp;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	last = *stack;
	if (last == NULL)
	{
		*stack = new;
		return ;
	}
	last = stacklast(*stack);
	last->next = new;
}

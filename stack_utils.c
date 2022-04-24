/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:20:54 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/24 20:07:28 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack);

t_stack	*stacknew(int n)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack) * 1);
	if (temp == NULL)
		return (NULL);
	temp->n = n;
	temp->simp_n = -1;
	temp->next = NULL;
	return (temp);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = *stack;
	if (last == NULL)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_deallocate(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*aux;

	curr = *stack_a;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*stack_a = NULL;
}

/*void	printf_list(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->simp_n);
		temp = temp->next;
	}
}*/

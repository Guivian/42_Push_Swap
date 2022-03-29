/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:33:59 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/24 23:16:07 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int argc, char **argv)
{
	int		*pre_stack;
	t_stack	*temp;
	int		i;

	pre_stack = malloc(sizeof(int) * (argc));
	if (pre_stack == NULL)
		return ;
	temp = NULL;
	i = 0;
	while (argv[++i])
		pre_stack[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc - 1)
	{
		temp = stacknew(pre_stack[i]);
		stackadd_front(stack_a, temp);
		temp = temp->next;
	}
}

t_stack	*stacknew(int n)
{
	t_stack	*head;
	t_stack	*temp;

	head = NULL;
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->n = n;
	temp->next = NULL;
	head = temp;
	return (head);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	printf_list(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->n);
		temp = temp->next;
	}
}

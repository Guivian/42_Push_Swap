/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:33:59 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/18 01:03:23 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int		*pre_stack;
	t_stack	*temp;
	int		i;

	pre_stack = malloc(sizeof(int) * (argc - 1));
	if (pre_stack == NULL)
		return ;
	temp = NULL;
	i = 0;
	while (argv[++i])
		pre_stack[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (pre_stack[++i])
	{
		temp = stacknew(pre_stack[i]);
		stackadd_front(&stack, temp);
		temp = temp->next;
	}
//	printf_list(stack);
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

void	printf_list(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	ft_printf("stack_a:\n");
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->n);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	init_stack(stack, argc, argv);
	printf_list(stack);
	switchtop(&stack);
	ft_printf("after sa: ");
	printf_list(stack);
}

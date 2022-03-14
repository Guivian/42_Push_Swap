/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:33:59 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/14 23:37:05 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_list(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	printf("stack_a:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

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
	while (pre_stack[i])
	{
		temp = stacknew(pre_stack[i]);
		stackadd_back(&stack, temp);
	}
	printf_list(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	init_stack(stack, argc, argv);
}

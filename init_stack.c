/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:33:59 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/14 21:20:31 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int	*pre_stack;
	int i;

	pre_stack = malloc(sizeof(int) * (argc - 1));
	if (pre_stack == NULL)
		return ;
	i = 0;
	while (argv[++i])
		pre_stack[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (pre_stack[i])
	{
		stack = stacknew(pre_stack[i]);
		stackadd_back(&stack, stack);
		ft_printf("%i\n", stack->n);
	}
}

int main(int argc, char **argv)
{
	t_stack *stack;

	stack = NULL;
	init_stack(stack, argc, argv);
}

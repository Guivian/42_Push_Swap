/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:44:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/18 18:53:01 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
/*	if (check_error(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}*/
	init_stack(&stack_a, argc, argv);
	ft_printf("stack_a: \n");
	printf_list(stack_a);
	push_b(&stack_a, &stack_b);
	ft_printf("stack_a: \n");
	printf_list(stack_a);
	push_b(&stack_a, &stack_b);
	ft_printf("stack_b: \n");
	printf_list(stack_b);
}

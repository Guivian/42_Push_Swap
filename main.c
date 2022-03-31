/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:44:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/31 16:17:10 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (check_error(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	init_stack(&stack_a, argc, argv);
	printf_list(stack_a);
	if (argc == 2)
		return (1);
	choose_algorithm(argc, &stack_a);
	printf_list(stack_a);
}

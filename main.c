/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:44:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/08 16:36:07 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	organize_chunk(int *ar, int argc);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*chunk;

	stack_a = NULL;
	chunk = NULL;
	if (check_error(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	chunk = init_stack(&stack_a, argc, argv);
	organize_chunk(chunk, argc);
	if (argc == 2)
		return (1);
	choose_algorithm(argc, &stack_a, chunk);
}

void	organize_chunk(int *ar, int argc)
{
	int	temp;
	int	i;
	int	j;

	i = -1;
	while (++i < (argc - 1))
	{
		j = i;
		while (++j < (argc - 1))
		{
			if (ar[i] > ar[j])
			{
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}
}

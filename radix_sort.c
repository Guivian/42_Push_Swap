/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:18:22 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/05 16:31:41 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	max_num = argc - 2;
	max_bits = 0;
	i = -1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < (argc - 1) && *stack_a != NULL)
		{
			if ((((*stack_a)->simp_n >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
		}
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
	}
}

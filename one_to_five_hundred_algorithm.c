/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five_hundred_algorithm.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:03:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/06 21:35:18 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_numbers1(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*temp;
	int		n;
	int		n_position;
	int		temp_argc;
	int		iterate_push_a;

	iterate_push_a = argc;
	while (--argc > 0)
	{
		temp = *stack_a;
		n_position = 1;
		n = temp->n;
		temp_argc = argc + 1;
		while (--temp_argc > 0)
		{
			if (temp->n < n)
				n = temp->n;
			temp = temp->next;
		}
		temp = *stack_a;
		while (temp->n != n)
		{
			n_position++;
			temp = temp->next;
		}
		if (n_position < (argc / 2))
		{
			n = 0;
			while (++n < n_position)
				rotate_a(stack_a);
		}
		else if (n_position >= (argc / 2))
		{
			n = argc + 1;
			while (--n >= n_position)
				reverse_rotate_a(stack_a);
		}
		else
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	while (--iterate_push_a > 0)
		push_a(stack_a, stack_b);
}

/*void	organize_chunk(int *ar, int argc)
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
}*/
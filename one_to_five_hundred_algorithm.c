/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five_hundred_algorithm.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:03:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/31 22:40:13 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	one_hundred_random_numbers(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*temp;
	int		n;
	int		i;
	int		test;

	test = -1;
	while (++test < argc)
	{
		temp = *stack_a;
		n = temp->n;
		i = 1;
		while (temp->next)
		{
			if (temp->n < n)
				n = temp->n;
			temp = temp->next;
		}
		temp = *stack_a;
		while (temp->n != n)
		{
			i++;
			temp = temp->next;
		}
		if (i < ((argc - 1) / 2) && (argc - 1) % 2 == 0)
		{
			n = -1;
			while (++n < i)
				rotate_a(stack_a);
		}
		else if (i > ((argc - 1) / 2) && (argc - 1) % 2 == 0)
		{
			n = argc + 1;
			while (--n > i)
				reverse_rotate_a(stack_a);
		}
		else
		{
			n = -1;
			while (++n != i)
				rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		argc--;
	}
	printf_list(*stack_b);
	ft_printf("\n");
}*/

void	one_hundred_random_numbers(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*temp;
	int		n;
	int		n_position;
	int		temp_argc;
	int		iterate_push_a;
	int		n_commands;

	n_commands = 0;

	iterate_push_a = argc;
	while (--argc > 0)
	{
		temp = *stack_a;
		n_position = 1;
		n =  temp->n;
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
			{
				rotate_a(stack_a);
				n_commands++;
			}
		}
		else if (n_position >= (argc / 2))
		{
			n = argc + 1;
			while (--n >= n_position)
			{
				reverse_rotate_a(stack_a);
				n_commands++;
			}
		}
		else
		{
			rotate_a(stack_a);
			n_commands++;
		}
		push_b(stack_a, stack_b);
		n_commands++;
	}
 	while (--iterate_push_a > 0)
	 {
		push_a(stack_a, stack_b);
		n_commands++;
	 }
	 ft_printf("number of commands = %i\n", n_commands);
}

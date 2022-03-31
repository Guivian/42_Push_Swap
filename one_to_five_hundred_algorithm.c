/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five_hundred_algorithm.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:03:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/29 13:18:15 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	**separe_chunks(int argc, char **argv)
{
	int	**chunks;
	int	*int_argv;
	int	i;

	chunks = malloc(sizeof(int) * (argc));
	int_argv = malloc(sizeof(int) * (argc));
	if (chunks == NULL || int_argv == NULL)
		return (0);
	i = -1;
	while (++i <= (argc - 1))
		chunks[i] = malloc(sizeof(int) * 1);
	i = 0;
	while (argv[++i])
		int_argv[i - 1] = ft_atoi(argv[i]);
}*/

void	one_hundred_random_numbers(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*temp;
	int		n;
	int		i;

	temp = *stack_a;
	n = temp->n;
	i = 0;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->n < n)
			n = temp->n;
	}
	temp = *stack_a;
	while (temp->n != n)
	{
		temp = temp->next;
		i++;
	}
	if (i < ((argc - 1) / 2) && (argc - 1) % 2 == 0)
	{
		n = -1;
		while (++n < i)
			rotate_a(stack_a);
	}
	else if (i > ((argc - 1) / 2) && (argc - 1) % 2 == 0)
	{
		while (--argc >= i)
			reverse_rotate_a(stack_a);
	}
	else
	{
		n = -1;
		while (++n != i)
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}

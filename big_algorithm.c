/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:03:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/08 17:33:31 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**separe_chunks(int	*chunk, int argc, int **new_chunks);

void	big_numbers1(t_stack **stack_a, t_stack **stack_b, int argc, int *ar)
{
	int		**new_chunks;
	t_stack	*temp;
	int		n;
	int		n_position;
	int		temp_argc;
	int		iterate_push_a;

	new_chunks = NULL;
	new_chunks = separe_chunks(ar, argc, new_chunks);
//	ft_printf("%i\n", new_chunks[2][10]);

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

int	**separe_chunks(int	*chunk, int argc, int **new_chunks)
{
	int	i;
	int	j;
	int	k;

	new_chunks = malloc(sizeof(int) * 5);
	if (new_chunks == NULL)
		return (0);
	i = -1;
	while (++i < 5)
	{
		new_chunks[i] = malloc(sizeof(int) * 20);
		if (new_chunks[i] == NULL)
			return (0);
	}
	i = -1;
	j = 0;
	k = -1;
	while (++i < (argc - 1))
	{
		if (i == 20 || i == 40 || i == 60 || i == 80)
		{
			j++;
			ft_printf("separe chunk\n");
			k = -1;
		}
		new_chunks[j][++k] = chunk[i];
		ft_printf("%i\n", new_chunks[j][k]);
	}
	return (new_chunks);
}

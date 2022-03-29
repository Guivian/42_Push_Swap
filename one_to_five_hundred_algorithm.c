/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five_hundred_algorithm.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:03:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/29 11:48:46 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**separe_chunks(int argc, char **argv)
{
	int	**chunks;
	int	i;

	chunks = malloc(sizeof(int) * (argc - 1));
	if (chunks == NULL)
		return (NULL);
	i = -1;
	while (++i <= (argc - 1))
		chunks[i] = malloc(sizeof(int) * (argc - 1));
}

void	one_hundred_random_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		n;

	temp = stack_a;
}

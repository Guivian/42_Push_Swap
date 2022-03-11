/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:24:53 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/11 20:13:47 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int	*pre_stack, int i);

int	check_error(int argc, char **argv)
{
	int	*pre_stack;
	int	i;

	i = 1;
	pre_stack = malloc(sizeof(int) * (argc - 1));
	if (pre_stack == NULL)
		return (0);
	while (argv[i])
	{
		if (ft_isint(argv[i]) == 0)
			return (0);
		pre_stack[i - 1] = ft_atoi(argv[i]);
		ft_printf("%i\n", pre_stack[i - 1]);
		i++;
	}
	if (check_duplicate(pre_stack, i) == 0)
		return (0);
	return (1);
}

int	check_duplicate(int	*pre_stack, int i)
{
	int	j;

	j = 1;
	i = 0;
	while (pre_stack[i])
	{
		j = 1;
		while (pre_stack[j + i])
		{
			if (pre_stack[j + i] == pre_stack[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	printf("%i %s\n", argc, *argv);
	if (check_error(argc, argv) == 0)
		printf("Error\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:24:53 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/22 19:28:25 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_argv(int argc, char **argv, long int *pre_stack);
int			check_duplicate(long int	*pre_stack, int i, int argc);
long int	ps_atoi(const char *str);

int	check_error(int argc, char **argv)
{
	long int	*pre_stack;

	if (argc == 1)
		return (0);
	pre_stack = malloc(sizeof(long int) * (argc));
	if (pre_stack == NULL)
		return (0);
	if (check_argv(argc, argv, pre_stack) == 0)
	{
		free(pre_stack);
		return (0);
	}
	free(pre_stack);
	return (1);
}

int	check_argv(int argc, char **argv, long int *pre_stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isint(argv[i]) == 0)
			return (0);
		if (argv[i][0] == '-' || argv[i][0] == '+')
			if (argv[i][1] < 48 || argv[i][1] > 57)
				return (0);
		pre_stack[i - 1] = ps_atoi(argv[i]);
		if (pre_stack[i - 1] > 2147483647 || pre_stack[i - 1] < -2147483648)
			return (0);
		i++;
	}
	if (check_duplicate(pre_stack, i, argc) == 0)
		return (0);
	return (1);
}

int	check_duplicate(long int	*pre_stack, int i, int argc)
{
	int	j;

	j = 1;
	i = 0;
	while (i <= argc - 1)
	{
		j = 1;
		while (j + i < argc - 1)
		{
			if (pre_stack[j + i] == pre_stack[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long int	ps_atoi(const char *str)
{
	int			i;
	int			value;
	long int	int_str;

	i = 0;
	value = 0;
	int_str = 0;
	if (str[i] == 45 && str[i + 1] >= 48 && str[i + 1] <= 57)
	{
		value = 1;
		i++;
	}
	else if (str[i] == 43 && str[i + 1] >= 48 && str[i + 1] <= 57)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		int_str = (int_str * 10) + (str[i] - 48);
		i++;
	}
	if (value == 1)
		int_str = int_str * (-1);
	return (int_str);
}

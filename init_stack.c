/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:43:34 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/03 17:10:04 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*simplify_input(int *pre_stack, int argc);
void	sort_array(int *arr, int argc);
void	bubble_sort(int *arr, int argc);

void	init_stack(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*temp;
	int		*pre_stack;
	int		*simp_n;
	int		i;

	pre_stack = malloc(sizeof(int) * (argc));
	if (pre_stack == NULL)
		return ;
	temp = NULL;
	simp_n = NULL;
	i = 0;
	while (argv[++i])
		pre_stack[i - 1] = ft_atoi(argv[i]);
	simp_n = simplify_input(pre_stack, argc);
	i = -1;
	while (++i < (argc - 1))
	{
		temp = stacknew(pre_stack[i], simp_n[i]);
		stackadd_back(stack_a, temp);
		temp = temp->next;
	}
	free(simp_n);
	free(pre_stack);
}

int	*simplify_input(int *pre_stack, int argc)
{
	int		*copy;
	int		*temp;
	int		i;
	int		j;

	i = -1;
	copy = NULL;
	temp = NULL;
	copy = ft_arrcpy(pre_stack, copy, (argc - 1));
	temp = ft_arrcpy(pre_stack, temp, (argc - 1));
	sort_array(temp, argc);
	while (++i < (argc - 1))
	{
		j = -1;
		while (++j < (argc - 1))
		{
			if (copy[i] == temp[j])
			{
				copy[i] = j;
				break ;
			}
		}
	}
	free(temp);
	return (copy);
}

void	sort_array(int *arr, int argc)
{
	int	temp;
	int	i;

	i = -1;
	temp = arr[i + 1];
	while (++i < (argc - 2))
		if (arr[i] > temp)
			temp = arr[i];
	i = -1;
	while (++i < (argc - 2))
	{
		if (arr[i] == temp)
		{
			arr[i] = arr[argc - 2];
			arr[argc - 2] = temp;
		}
	}
	bubble_sort(arr, argc);
}

void	bubble_sort(int *arr, int argc)
{
	int		i;
	int		j;
	int		temp;
	bool	swapped;

	i = -1;
	while (++i < (argc - 2))
	{
		swapped = false;
		j = -1;
		while (++j < (argc - i - 2))
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if (swapped == false)
			break ;
	}
}

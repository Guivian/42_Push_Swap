/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:43:34 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/22 20:46:49 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplify_input(int *pre_stack, t_stack **stack_a, int argc);
void	sort_array(int *arr, int argc);
void	swap(int *x, int *y);
void	bubble_sort(int *arr, int argc);

void	init_stack(t_stack **stack_a, int argc, char **argv)
{
	int		*pre_stack;
	t_stack	*temp;
	int		i;

	pre_stack = malloc(sizeof(int) * (argc));
	if (pre_stack == NULL)
		return ;
	temp = NULL;
	i = 0;
	while (argv[++i])
		pre_stack[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc - 1)
	{
		temp = stacknew(pre_stack[i]);
		stackadd_back(stack_a, temp);
		temp = temp->next;
	}
//	simplify_input(pre_stack, stack_a, argc);
	free(pre_stack);
}

void	simplify_input(int *pre_stack, t_stack **stack_a, int argc)
{
	int	*copy;
	int	i;
	int	j;

	copy = pre_stack;
	i = -1;
	sort_array(copy, argc);
	while (++i < (argc - 1))
	{
		j = -1;
		while (++j < (argc - 1))
			if (pre_stack[i] == copy[j])
				pre_stack[i] = j;
	}
	i = -1;
	while (++i < (argc - 1))
	{
		(*stack_a)->simp_n = pre_stack[i];
		*stack_a = (*stack_a)->next;
	}
}

void	sort_array(int *arr, int argc)
{
	int	temp;
	int	i;

	i = -1;
//	temp = arr[i];
	while (++i < (argc - 1))
		if (arr[i] > temp)
			temp = arr[i];
	i = -1;
	while (++i < (argc - 1))
	{
		if (arr[i] == temp)
		{
			arr[i] = arr[argc - 1];
			arr[argc - 1] = temp;
		}
	}
	bubble_sort(arr, argc);
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	bubble_sort(int *arr, int argc)
{
	int		i;
	int		j;
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
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break ;
	}
}

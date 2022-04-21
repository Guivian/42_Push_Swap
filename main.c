/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:44:31 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/04/21 18:55:48 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int argc, char **argv);
int		check_if_organized(t_stack **stack_a);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (check_error(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	init_stack(&stack_a, argc, argv);
	if (argc == 2)
		return (1);
	if (check_if_organized(&stack_a) == 1)
		return (1);
	choose_algorithm(argc, &stack_a);
	free(stack_a);
}

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
	free(pre_stack);
}

int	check_if_organized(t_stack **stack_a)
{
	int		i;
	t_stack	*temp;

	temp = (*stack_a)->next;
	i = (*stack_a)->n;
	while (temp->next)
	{
		if (i > temp->n)
			return (0);
		i = temp->n;
		temp = temp->next;
	}
	if (temp->next == NULL && i > temp->n)
		return (0);
	return (1);
}

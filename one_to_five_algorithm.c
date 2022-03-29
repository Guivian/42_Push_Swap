/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _to_five_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:48:03 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/25 20:30:17 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_random_numbers(t_stack **stack_a);
void	five_random_numbers(t_stack **stack_a, t_stack **stack_b, int argc);
void	organize_from_stack_b_1(t_stack **stack_a, t_stack *temp, int n);
void	organize_from_stack_b_2(t_stack **stack_a, t_stack *temp, int n);

void	choose_algorithm(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 3)
	{
		if ((*stack_a)->n > (*stack_a)->next->n)
			swap_top2_a(stack_a);
	}
	else if (argc == 4)
		three_random_numbers(stack_a);
	else if (argc == 5 || argc == 6)
		five_random_numbers(stack_a, &stack_b, argc);
	else
	{
		ft_printf("Not ready yet!\n");
	}
}

void	three_random_numbers(t_stack **stack_a)
{
	if ((*stack_a)->n > (*stack_a)->next->n)
	{
		if ((*stack_a)->next->n > (*stack_a)->next->next->n)
		{
			swap_top2_a(stack_a);
			reverse_rotate_a(stack_a);
		}
		else
		{
			if ((*stack_a)->n > (*stack_a)->next->next->n)
				rotate_a(stack_a);
			else
				swap_top2_a(stack_a);
		}
	}
	else if ((*stack_a)->n < (*stack_a)->next->n)
	{
		if ((*stack_a)->n > (*stack_a)->next->next->n)
			reverse_rotate_a(stack_a);
		else if ((*stack_a)->next->n > ((*stack_a)->next->next->n))
		{
			reverse_rotate_a(stack_a);
			swap_top2_a(stack_a);
		}
	}
}

void	five_random_numbers(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int		n;
	t_stack	*temp;

	n = 0;
	push_b(stack_a, stack_b);
	if (argc == 6)
		push_b(stack_a, stack_b);
	three_random_numbers(stack_a);
	if (argc == 6 && (*stack_b)->n > (*stack_b)->next->n)
		swap_top2_b(stack_b);
	push_a(stack_a, stack_b);
	temp = *stack_a;
	organize_from_stack_b_1(stack_a, temp, n);
	if (argc == 6)
	{
		push_a(stack_a, stack_b);
		temp = *stack_a;
		organize_from_stack_b_2(stack_a, temp, n);
	}
}

void	organize_from_stack_b_1(t_stack **stack_a, t_stack *temp, int n)
{
	while (temp->next != NULL)
	{
		temp = temp->next;
		if ((*stack_a)->n > temp->n)
			n++;
	}
	if (n == 1)
		swap_top2_a(stack_a);
	else if (n == 2)
	{
		reverse_rotate_a(stack_a);
		swap_top2_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (n == 3)
		rotate_a(stack_a);
}

void	organize_from_stack_b_2(t_stack **stack_a, t_stack *temp, int n)
{
	while (temp->next != NULL)
	{
		temp = temp->next;
		if ((*stack_a)->n > temp->n)
			n++;
	}
	if (n == 1)
		swap_top2_a(stack_a);
	else if (n == 2)
	{
		swap_top2_a(stack_a);
		rotate_a(stack_a);
		swap_top2_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (n == 3)
	{
		reverse_rotate_a(stack_a);
		swap_top2_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (n == 4)
		rotate_a(stack_a);
}

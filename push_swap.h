/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:16:01 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/14 21:18:22 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

int		check_error(int argc, char **argv);
t_stack	*stacknew(int n);
t_stack	*stacklast(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
#endif

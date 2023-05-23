/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:49:51 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/23 22:16:28 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

int	sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	write(1, "ss\n", 3);
	return (1);
}

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->size_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

int	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->size_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	write(1, "rb\n", 3);
	return (1);
}

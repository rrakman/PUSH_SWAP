/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:59:56 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/21 14:05:54 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < stack->size_a)
	{
		i++;
		len++;
	}
	tmp = stack->stack_a[len - 1];
	while (i >= 0)
	{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
	}
	stack->stack_a[0] = tmp;
	stack->stack_a[len] = 0;
	write(1, "rra\n", 4);
}

int	rrb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < stack->size_b)
	{
		i++;
		len++;
	}
	tmp = stack->stack_b[len - 1];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	stack->stack_b[len] = 0;
	write(1, "rrb\n", 4);
	return (1);
}

int	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	write(1, "rr\n", 3);
	return (1);
}

int	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 4);
	return (1);
}

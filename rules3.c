/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:05:59 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/21 14:11:48 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lol_norm_pa(t_stack *stack, int j)
{
	stack->stack_b[j - 1] = 0;
	stack->size_b--;
	stack->size_a++;
	write(1, "pa\n", 3);
}

int	pa(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->size_b != 0)
	{
		while (i < stack->size_a)
			i++;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = stack->stack_b[0];
		while (j < stack->size_b)
		{
			stack->stack_b[j] = stack->stack_b[j + 1];
			j++;
		}
		lol_norm_pa(stack, j);
	}
	return (1);
}

void	lol_norm_pb(t_stack *stack, int j)
{
	stack->stack_a[j - 1] = 0;
	stack->size_a--;
	stack->size_b++;
	write(1, "pb\n", 3);
}

int	pb(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->size_a != 0)
	{
		while (i < stack->size_b)
			i++;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = stack->stack_a[0];
		while (j < stack->size_a)
		{
			stack->stack_a[j] = stack->stack_a[j + 1];
			j++;
		}
		lol_norm_pb(stack, j);
	}
	return (1);
}

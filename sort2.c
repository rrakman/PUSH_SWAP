/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:15:07 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/21 15:52:37 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_cpy(t_stack *stack)
{
	int	i;

	i = 0;
	stack->cpy = malloc(sizeof(int) * stack->size_a);
	while (i < stack->size_a)
	{
		stack->cpy[i] = stack->stack_a[i];
		i++;
	}
}

void	bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	stack_cpy(stack);
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->cpy[i] > stack->cpy[j])
			{
				tmp = stack->cpy[i];
				stack->cpy[i] = stack->cpy[j];
				stack->cpy[j] = tmp;
			}
			j++;
		}
	i++;
	}
}

int	find_maximum(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack_b[0];
	while (i < stack->size_b)
	{
		if (stack->stack_b[i] > max)
			max = stack->stack_b[i];
		i++;
	}
	return (max);
}

int	get_index_b(t_stack *stack, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->stack_b[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	get_index(t_stack *stack, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->cpy[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

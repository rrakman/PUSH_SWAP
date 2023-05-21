/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:33:04 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/21 16:31:37 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_or_down(t_stack *stack, int num, int size)
{
	if (get_index_b(stack, num, size) < stack->size_b / 2)
		return (1);
	return (0);
}

void	move_elem_to_top(t_stack *stack, int num)
{
	int	i;

	i = up_or_down(stack, num, stack->size_b);
	while (stack->stack_b[0] != num)
	{
		if (i == 1)
		{
			if (stack->stack_b[0] != num)
				rb(stack);
		}
		else
		{
			if (stack->stack_b[0] != num)
				rrb(stack);
		}
	}
}

void	sort_100(t_stack *stack)
{
	int	f_range;
	int	s_range;
	int	s;
	int	index;

	f_range = 0;
	s_range = 15;
	s = stack->size_a;
	bubble_sort(stack);
	while (stack->size_a > 0)
	{
		index = get_index(stack, stack->stack_a[0], s);
		process_index(stack, index, &f_range, &s_range);
	}
	while (stack->size_b)
	{
		move_elem_to_top(stack, find_maximum(stack));
		pa(stack);
	}
}

void	process_index(t_stack *stack, int index, int *f_range, int *s_range)
{
	if (index >= *f_range && index <= *s_range)
	{
		pb(stack);
		(*f_range)++;
		(*s_range)++;
	}
	else if (index < *f_range)
	{
		pb(stack);
		rb(stack);
		(*f_range)++;
		(*s_range)++;
	}
	else if (index > *s_range)
		ra(stack);
}

void	sort_500(t_stack *stack)
{
	int	f_range;
	int	s_range;
	int	s;
	int	index;

	f_range = 0;
	s_range = 34;
	s = stack->size_a;
	bubble_sort(stack);
	while (stack->size_a > 0)
	{
		index = get_index(stack, stack->stack_a[0], s);
		process_index(stack, index, &f_range, &s_range);
	}
	while (stack->size_b)
	{
		move_elem_to_top(stack, find_maximum(stack));
		pa(stack);
	}
}

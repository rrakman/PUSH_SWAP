/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:48:18 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/21 16:32:52 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}

void	sort_3(t_stack *stack)
{
	if (stack->stack_a[2] < stack->stack_a[1] \
		&& stack->stack_a[0] < stack->stack_a[2] \
			&& stack->stack_a[0] < stack->stack_a[1])
	{
		rra(stack);
		sa(stack);
	}
	else if (stack->stack_a[0] > stack->stack_a[1] \
		&& stack->stack_a[1] < stack->stack_a[2] \
			&& stack->stack_a[0] < stack->stack_a[2])
		sa(stack);
	else if (stack->stack_a[0] < stack->stack_a[1] \
		&& stack->stack_a[1] > stack->stack_a[2] \
			&& stack->stack_a[0] > stack->stack_a[2])
		rra(stack);
	else if (stack->stack_a[0] > stack->stack_a[1] \
		&& stack->stack_a[1] < stack->stack_a[2] \
			&& stack->stack_a[0] > stack->stack_a[2])
		ra(stack);
	else
	{
		ra(stack);
		sa(stack);
	}
}

int	find_smallest_number(t_stack *stack)
{
	int	i;
	int	smallest;
	int	j;

	j = 0;
	i = 0;
	smallest = stack->stack_a[0];
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < smallest)
		{
			smallest = stack->stack_a[i];
			j = i;
		}
		i++;
	}
	stack->smallest = smallest;
	return (j);
}

void	sort_4(t_stack *stack)
{
	find_smallest_number(stack);
	while (stack->stack_a[0] != stack->smallest)
		ra(stack);
	pb(stack);
	if (!is_stack_sorted(stack))
	{
		sort_3(stack);
	}
	pa(stack);
}

void	sort_5(t_stack *stack)
{
	int	i;

	i = find_smallest_number(stack);
	while (stack->stack_a[0] != stack->smallest)
	{
		if (i >= (stack->size_a / 2))
			rra(stack);
		else
			ra(stack);
	}
	pb(stack);
	i = find_smallest_number(stack);
	while (stack->stack_a[0] != stack->smallest)
	{
		if (i >= (stack->size_a / 2))
			rra(stack);
		else
			ra(stack);
	}
	pb(stack);
	if (!is_stack_sorted(stack))
		sort_3(stack);
	pa(stack);
	pa(stack);
}

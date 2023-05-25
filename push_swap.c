/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:54:46 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/25 18:03:34 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_stack(char **av, t_stack *stack)
{
	char	*s;
	int		*result;

	s = concatenate_strings(av);
	result = convert_strings_to_integers(s, stack);
	return (result);
}

int	input_size(int ac, char **av, t_stack *stack)
{
	int	i;
	int	j;

	j = 0;
	stack->size_a = 0;
	while (++j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (!ft_isdigit(av[j][i]))
				ft_error();
			if (ft_isdigit(av[j][i]))
				stack->size_a++;
			else if (av[j][i] != ' ' && av[j][i] != '\t')
				ft_error();
			while (ft_isdigit(av[j][i]))
				i++;
			if (av[j][i] != ' ' && av[j][i] != '\t' && av[j][i] != '\0')
				ft_error();
			while (av[j][i] == ' ' || av[j][i] == '\t')
				i++;
		}
	}
	return (stack->size_a);
}

void	err_duplicated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a - 1)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_sort(t_stack *stack)
{
	if (stack->size_a == 2)
		sort_2(stack);
	else if (stack->size_a == 3)
		sort_3(stack);
	else if (stack->size_a == 4)
		sort_4(stack);
	else if (stack->size_a == 5)
		sort_5(stack);
	else if (stack->size_a <= 100)
		sort_100(stack);
	else
		sort_500(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	ft_input(ac, av);
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size_a = input_size(ac, av, stack);
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->size_a));
	stack->stack_a = ft_make_stack(av, stack);
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->size_b));
	stack->size_b = 0;
	err_duplicated(stack);
	if (is_stack_sorted(stack))
	{
		free(stack->stack_a);
		free(stack->stack_b);
		exit(0);
	}
	ft_sort(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	return (0);
}

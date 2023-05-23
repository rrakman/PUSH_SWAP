/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:14:06 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/23 20:28:09 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_input(int ac, char **av)
{
	size_t	i;
	size_t	nspace;
	int		j;

	j = 0;
	if (ac < 2)
		exit (1);
	while (++j < ac)
	{
		if (ft_strlen(av[j]) == 0)
			ft_error();
		i = 0;
		nspace = 0;
		while (i < ft_strlen(av[j]))
		{
			if (av[j][i++] == ' ')
				nspace++;
		}
		if (ft_strlen(av[j]) == nspace)
			ft_error();
	}	
}

int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*concatenate_strings(char **av)
{
	char	*s;
	int		i;

	s = NULL;
	i = 1;
	while (av[i])
	{
		s = ft_strjoin(s, ft_strdup(av[i]));
		s = ft_strjoin(s, ft_strdup(" "));
		i++;
	}
	return (s);
}

int	*convert_strings_to_integers(char *s, t_stack *stack)
{
	char	**str;
	int		i;

	str = ft_split(s, ' ');
	free(s);
	i = 0;
	while (str[i])
	{
		stack->stack_a[i] = ft_atol(str[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (stack->stack_a);
}

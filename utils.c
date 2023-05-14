#include "push_swap.h"

void	ft_error()
{
	write(2,"Error\n",6);
	exit(1);
}

void	ft_input(int ac,char **av)
{
	size_t	i;
	size_t	nspace;
	int		j;
	
	j = 0;
	if (ac < 2)
		exit (-1);
	while(++j < ac)
	{
		if(ft_strlen(av[j]) == 0)
			ft_error();
		i = 0;
		nspace = 0;
		while (i < ft_strlen(av[j]))
		{
			if(av[j][i++] == ' ')
				nspace++;
		}
		if (ft_strlen(av[j]) == nspace)
			ft_error();
	}	
}

void is_stack_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while(stack->stack_a[i])
	{
		if((stack->stack_a[i] < stack->stack_a[i + 1]) && (stack->stack_a[i] < stack->stack_a[i+2]) && (stack->stack_a[i + 2] != '\0'))
			exit(0);
		i++;
	}
}
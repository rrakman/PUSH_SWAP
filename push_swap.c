# include "push_swap.h"


int *ft_make_stack(char **av,t_stack *stack)
{
	char **str;

	str = NULL;
	int i = 1;
	char *s = "";
	while (av[i])
	{
		while(av[i])
		{
			s = ft_strjoin(s,av[i]);
			s = ft_strjoin(s," ");
			i++;
		}
	}
	str = ft_split(s,' ');
	free(s);
	i = 0;
	while(str[i])
	{
		stack->stack_a[i] = ft_atol(str[i]);
		i++;
	}
	return (stack->stack_a);
}

int	input_size(int ac,char **av,t_stack *stack)
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
			if(ft_isdigit(av[j][i]))
				stack->size_a++;
			else if (av[j][i] != ' ' && av[j][i] != '\t')
				ft_error();
			while (ft_isdigit(av[j][i]))
				i++;
			if(av[j][i] != ' ' && av[j][i] != '\t' && av[j][i] != '\0')
				ft_error();
			while (av[j][i] == ' ' || av[j][i] == '\t')
				i++;
		}
	}
	return (stack->size_a);
}

void err_duplicated(t_stack *stack)
{
	int i, j;

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

int	main(int ac,char **av)
{
	t_stack *stack;
	
	ft_input(ac,av);
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size_a = input_size(ac,av,stack);
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->size_a));
	stack->stack_a = ft_make_stack(av,stack);
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->size_b));
	stack->size_b = 0;
	err_duplicated(stack);
	is_stack_sorted(stack);
	if(stack->size_a == 2)
		sort_2(stack);
	else if(stack->size_a == 3)
		sort_3(stack);
	int i = 0;
	while(stack->stack_a[i])
	{
		printf("%d\n",stack->stack_a[i]);
		i++;
	}
}
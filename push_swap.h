# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>


# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "LIBFT/libft.h"

typedef struct s_stack
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;

}t_stack;


void	ft_input(int ac,char **av);
void    ft_error();
void    is_stack_sorted(t_stack *stack);
void    err_duplicated(t_stack *stack);


int     input_size(int ac,char **av,t_stack *stack);
int     *ft_make_stack(char **av,t_stack *stack);

int     sa(t_stack *stack);
int     ra(t_stack *stack);
int     rra(t_stack *stack);

# endif
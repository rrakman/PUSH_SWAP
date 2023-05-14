#include "push_swap.h"

void    sort_2(t_stack *stack)
{
    if (stack->stack_a[0] > stack->stack_a[1])
        sa(stack);
}

void    sort_3(t_stack *stack)
{
    if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[0] < stack->stack_a[2])
        sa(stack);
    else if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2])
    {
        sa(stack);
        rra(stack);
    }
    else if ((stack->stack_a[0] > stack->stack_a[1]) && (stack->stack_a[0] < stack->stack_a[2]) && (stack->stack_a[1] < stack->stack_a[2]))
        ra(stack);
    else if (stack->stack_a[0] < stack->stack_a[1] && (stack->stack_a[0] < stack->stack_a[2]) && stack->stack_a[1] > stack->stack_a[2])
        sa(stack);
    else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2])
        rra(stack);
    else
        printf("hhh\n");
}
int find_maximum(t_stack *stack)
{
    int i;
    int max;

    i = 0;
    max = stack->stack_a[0];
    while (stack->stack_a[i])
    {
        if (stack->stack_a[i] > max)
            max = stack->stack_a[i];
        i++;
    }
    return (max);
}
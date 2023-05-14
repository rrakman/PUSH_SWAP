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
    else if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] < stack->stack_a[2])
        ra(stack);
    else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2])
    {
        sa(stack);
        ra(stack);
    }
    else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] < stack->stack_a[2])
        rra(stack);
}


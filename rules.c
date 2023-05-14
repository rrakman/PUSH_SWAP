#include "push_swap.h"

int sa(t_stack *stack)
{
    int tmp;

    if (stack->stack_a[0] && stack->stack_a[1])
    {
        tmp = stack->stack_a[0];
        stack->stack_a[0] = stack->stack_a[1];
        stack->stack_a[1] = tmp;
        write(1,"sa\n",3);
    }
    return (1);
}

int ra(t_stack *stack)
{
    int tmp;
    int i;

    i = 0;
    if (stack->stack_a[0])
    {
        tmp = stack->stack_a[0];
        while (stack->stack_a[i])
        {
            stack->stack_a[i] = stack->stack_a[i + 1];
            i++;
        }
        stack->stack_a[i - 1] = tmp;
        write(1,"ra\n",3);
    }
    return (1);
}

int rra(t_stack *stack)
{
    int tmp;
    int i;

    int len = 0;
    i = 0;
    if (stack->stack_a[0])
    {
        while (stack->stack_a[i])
        {
            i++;
            len++;
        }
        tmp = stack->stack_a[len - 1];
        while (i > 0)
        {
            stack->stack_a[i] = stack->stack_a[i - 1];
            i--;
        }
        stack->stack_a[0] = tmp;
        stack->stack_a[len] = 0;
        write(1,"rra\n",4);
    }
    return (1);
}

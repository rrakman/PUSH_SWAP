#include "push_swap.h"

int sa(t_stack *stack)
{
    int tmp;

    if (stack->stack_a[0] && stack->stack_a[1])
    {
        tmp = stack->stack_a[0];
        stack->stack_a[0] = stack->stack_a[1];
        stack->stack_a[1] = tmp;
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
    }
    return (1);
}

int *pa(t_stack *stack)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 0;
    if (stack->stack_b[0])
    {
        while (stack->stack_a[i])
            i++;
        tmp = stack->stack_b[0];
        while (stack->stack_b[j])
        {
            stack->stack_b[j] = stack->stack_b[j + 1];
            j++;
        }
        stack->stack_a[i] = tmp;
        stack->stack_a[i + 1] = 0;
    }
    return (stack->stack_a);
}

int *pb(t_stack *stack)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 0;
    if (stack->stack_a[0])
    {
        while (stack->stack_b[i])
            i++;
        tmp = stack->stack_a[0];
        while (stack->stack_a[j])
        {
            stack->stack_a[j] = stack->stack_a[j + 1];
            j++;
        }
        stack->stack_b[i] = tmp;
        stack->stack_b[i + 1] = 0;
    }
    return (stack->stack_b);
}
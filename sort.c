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
    else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2] && stack->stack_a[0] < stack->stack_a[2])
        sa(stack);
    else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2] && stack->stack_a[0] > stack->stack_a[2])
        rra(stack);
}

int find_smallest_number(t_stack *stack)
{
    int i;
    int smallest;

    i = 0;
    smallest = stack->stack_a[0];
    while (i < stack->size_a)
    {
        if (stack->stack_a[i] < smallest)
            smallest = stack->stack_a[i];
        i++;
    }
    stack->smallest = smallest;
    return (i);
}

void sort_4(t_stack *stack)
{
    find_smallest_number(stack);
    while (stack->stack_a[0] != stack->smallest)
        ra(stack);
    pb(stack);
    sort_3(stack);
    pa(stack);  
}

void sort_5(t_stack *stack)
{
    int i = find_smallest_number(stack);
    while (stack->stack_a[0] != stack->smallest)
    {   
        if (i > (stack->size_a / 2))
            rra(stack);
        else
            ra(stack);
    }
    pb(stack);
    sort_4(stack);
    pa(stack);
}

void stack_cpy(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size_a)
    {
        stack->cpy[i] = stack->stack_a[i];
        //printf("stack->cpy[%d] = %d\n", i, stack->cpy[i]-1);
        i++;
    }
}

void bubble_sort(t_stack *stack)
{
    int i;
    int j;
    int tmp;

    i = 0;
    stack_cpy(stack);
    while (i < stack->size_a)
    {
        j = i + 1;
        while (j < stack->size_a)
        {
            if (stack->cpy[i] > stack->cpy[j])
            {
                tmp = stack->cpy[i];
                stack->cpy[i] = stack->cpy[j];
                stack->cpy[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
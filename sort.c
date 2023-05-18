#include "push_swap.h"

void    sort_2(t_stack *stack)
{
    if (stack->stack_a[0] > stack->stack_a[1])
        sa(stack);
}

void    sort_3(t_stack *stack)
{
    if (stack->stack_a[2] < stack->stack_a[1] && stack->stack_a[0] < stack->stack_a[2] && stack->stack_a[0] < stack->stack_a[1])
    {
        rra(stack);
        sa(stack);
    }
    else if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] < stack->stack_a[2] && stack->stack_a[0] < stack->stack_a[2])
        sa(stack);
    else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2] && stack->stack_a[0] > stack->stack_a[2])
        rra(stack);
    else if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] < stack->stack_a[2] && stack->stack_a[0] > stack->stack_a[2])
        ra(stack);
    else
    {
        ra(stack);
        sa(stack);
    }
}

int find_smallest_number(t_stack *stack)
{
    int i;
    int smallest;

    i = 0;
    int j = 0;
    smallest = stack->stack_a[0];
    while (i < stack->size_a)
    {
        if (stack->stack_a[i] < smallest)
        {
            smallest = stack->stack_a[i];
            j = i;
        }
        i++;
    }
    // printf("index j = %d\n", j);
    // printf("index of small %d\n",i);
    // printf("smallest = %d\n", smallest);
    // exit(1);
    stack->smallest = smallest;
    return (j);
}

void sort_4(t_stack *stack)
{
    find_smallest_number(stack);
    while (stack->stack_a[0] != stack->smallest)
        ra(stack);
    pb(stack);
    if (!is_stack_sorted(stack))
    {
        sort_3(stack);
    }
    pa(stack);
}

void sort_5(t_stack *stack)
{
    int i = find_smallest_number(stack);
    printf("i = %d\n", i);
    printf("stack smallest = %d\n", stack->smallest);

    while (stack->stack_a[0] != stack->smallest)
    {
        if (i >= (stack->size_a / 2))
            rra(stack);
        else
            ra(stack);
    }
    pb(stack);
    i = find_smallest_number(stack);
    while (stack->stack_a[0] != stack->smallest)
    {
        if (i >= (stack->size_a / 2))
            rra(stack);
        else
            ra(stack);
    }
    pb(stack);
    if(!is_stack_sorted(stack))
        sort_3(stack);
    pa(stack);
    pa(stack);
    
}

void stack_cpy(t_stack *stack)
{
    int i;

    i = 0;
    stack->cpy = malloc(sizeof(int) * stack->size_a);
    while (i < stack->size_a)
    {
        stack->cpy[i] = stack->stack_a[i];
        // printf("stack->cpy[%d] = %d\n", i, stack->cpy[i]-1);
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

// int is_in_range(int num, t_stack *stack, int range, int range2)
// {
//     while (range <= range2)
//     {
//         if (stack->stack_a[range] == num || stack->stack_a[range2] == num)
//             return (1);
//         range++;
//     }
//     return (0);
// }

int is_after(int num, t_stack *stack, int range)
{
    while (range <= stack->size_a)
    {
        if (stack->cpy[range] == num)
            return (1);
        range++;
    }
    return (0);
}

// int is_before(int num, t_stack *stack, int range)
// {
//     while (range >= 0)
//     {
//         if (stack->cpy[range] == num)
//             return (1);
//         range--;
//     }
//     return (0);
// }

void sort_100(t_stack *stack)
{
    bubble_sort(stack);
    int i = 0;
    while (i < stack->size_a)
    {
        printf("cpy[%d] = %d\n", i,stack->cpy[i]);
        i++;
    }
    printf("res %d\n",is_after(stack->stack_a[0], stack, 15));
}

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
    // printf("i = %d\n", i);
    // printf("stack smallest = %d\n", stack->small```````1szzc  est);

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

int find_maximum(t_stack* stack)
{
    int i = 0;
    int max = stack->stack_b[0];
    while (i < stack->size_b)
    {
        if (stack->stack_b[i] > max)
            max = stack->stack_b[i];
        i++;
    }
    return max;
}

int get_index_b(t_stack *stack, int num , int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (stack->stack_b[i] == num)
            return i;
        i++;
    }
    return -1;
}

int get_index(t_stack *stack, int num , int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (stack->cpy[i] == num)
            return i;
        i++;
    }
    return -1;
}

int up_or_down(t_stack *stack, int num , int size)
{
    if (get_index_b(stack, num,size) < stack->size_b / 2)
        return 1;
    return 0;
}

void move_elem_to_top(t_stack *stack, int num)
{
    int i = up_or_down(stack, num , stack->size_b);
    while (stack->stack_b[0] != num){
    if (i == 1)
    {
        if (stack->stack_b[0] != num)
            rb(stack);
    }
    else
    {
        if (stack->stack_b[0] != num)
            rrb(stack);
    }
    }
}

void sort_100(t_stack *stack)
{
    bubble_sort(stack);
    static int f_range = 0;
    int s_range = 15;
    int s = stack->size_a;
    while (stack->size_a > 0)
    {
        if (get_index(stack,stack->stack_a[0],s) >= f_range && get_index(stack,stack->stack_a[0],s) <= s_range)
        {
            pb(stack);
            f_range++;
            s_range++;
        }
        else if (get_index(stack,stack->stack_a[0],s) < f_range)
        {
            pb(stack);
            rb(stack);
            f_range++;
            s_range++;
        }
        else if (get_index(stack,stack->stack_a[0],s) > s_range)
            ra(stack);
    }
    while (stack->size_b)
    {
        move_elem_to_top(stack, find_maximum(stack));
        pa(stack);
    }
}
 
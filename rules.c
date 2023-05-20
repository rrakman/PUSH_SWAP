#include "push_swap.h"

void sa(t_stack *stack)
{
    int tmp;

    // if (stack->stack_a[0] && stack->stack_a[1])
    // {
        tmp = stack->stack_a[0];
        stack->stack_a[0] = stack->stack_a[1];
        stack->stack_a[1] = tmp;
        write(1,"sa\n",3);
    // }
}

int sb(t_stack *stack)
{
    int tmp;

    // if (stack->stack_b[0] && stack->stack_b[1])
    // {
        tmp = stack->stack_b[0];
        stack->stack_b[0] = stack->stack_b[1];
        stack->stack_b[1] = tmp;
        write(1,"sb\n",3);
    // }
    return (1);
}

int ss(t_stack *stack)
{
    sa(stack);
    sb(stack);
	write(1,"ss\n",3);
    return (1);
}

void ra(t_stack *stack)
{
    int tmp;
    int i;

    i = 0;
    tmp = stack->stack_a[0];
    while (i < stack->size_a)
    {
        stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
    }
    stack->stack_a[i - 1] = tmp;
    write(1,"ra\n",3);
}

int rb(t_stack *stack)
{
    int tmp;
    int i;

    i = 0;
    // if (stack->stack_b[0])
    // {
        tmp = stack->stack_b[0];
        while (i < stack->size_b)
        {
            stack->stack_b[i] = stack->stack_b[i + 1];
            i++;
        }
        stack->stack_b[i - 1] = tmp;
        write(1,"rb\n",3);
    // }
    return (1);
}

void rra(t_stack *stack)
{
    int tmp;
    int i;

    int len = 0;
    i = 0;
    // if (stack->stack_a[0])
    // {
        // while (stack->stack_a[i])
        // {
        //     i++;
        //     len++;
        // }
        while (i < stack->size_a)
        {
            i++;
            len++;
        }
        tmp = stack->stack_a[len - 1];
        while (i >= 0)
        {
            stack->stack_a[i] = stack->stack_a[i - 1];
            i--;
        }
        stack->stack_a[0] = tmp;
        stack->stack_a[len] = 0;
        write(1,"rra\n",4);
    // }
}

int	rrb(t_stack *stack)
{
    int tmp;
    int i;

    int len = 0;
    i = 0;
    // if (stack->stack_b[0])
    // {
        while (i < stack->size_b)
        {
            i++;
            len++;
        }
        tmp = stack->stack_b[len - 1];
        while (i > 0)
        {
            stack->stack_b[i] = stack->stack_b[i - 1];
            i--;
        }
        stack->stack_b[0] = tmp;
        stack->stack_b[len] = 0;
        write(1,"rrb\n",4);
    // }
    return (1);
}

int rr(t_stack *stack)
{
    ra(stack);
    rb(stack);
	write(1,"rr\n",3);
    return(1);
}

// void pa(t_stack *stack)
// {
//     int i;

//     i = 0;
//     if (stack->size_b != 0)
//     {
//         i = stack->size_a - 1;
//         stack->size_a++;
//         while (i >= 0)
//         {
//             int temp = stack->stack_a[i];
//             stack->stack_a[i + 1] = temp;
//             stack->stack_a[i] = stack->stack_a[i - 1];
//             i--;
//         }
//         stack->stack_a[0] = stack->stack_b[stack->size_b - 1];
//         stack->size_b--;
//         write(1,"pa\n",3);
//     }
// }

int pa(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (stack->size_b != 0)
    {
        while (i < stack->size_a)
            i++;
        while (i > 0)
        {
            stack->stack_a[i] = stack->stack_a[i - 1];
            i--;
        }
        stack->stack_a[0] = stack->stack_b[0];
        while (j < stack->size_b)
        {
            stack->stack_b[j] = stack->stack_b[j + 1];
            j++;
        }
        stack->stack_b[j - 1] = 0;
        stack->size_b--;
        stack->size_a++;
        write(1,"pa\n",3);
    }
    return (1);
}

int pb(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (stack->size_a != 0)
    {
        while (i < stack->size_b)
            i++;
        while (i > 0)
        {
            stack->stack_b[i] = stack->stack_b[i - 1];
            i--;
        }
        stack->stack_b[0] = stack->stack_a[0];
        while (j < stack->size_a)
        {
            stack->stack_a[j] = stack->stack_a[j + 1];
            j++;
        }
        stack->stack_a[j - 1] = 0;
        stack->size_a--;
        stack->size_b++;
        write(1,"pb\n",3);
    }
    return (1);
}

int	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	write(1,"rrr\n",4);
	return (1);
}
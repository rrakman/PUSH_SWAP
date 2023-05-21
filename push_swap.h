/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:47 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/21 16:29:50 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "LIBFT/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	smallest;
	int	*cpy;
}t_stack;

void	ft_error(void);
void	ft_input(int ac, char **av);
void	err_duplicated(t_stack *stack);

int		is_stack_sorted(t_stack *stack);
int		input_size(int ac, char **av, t_stack *stack);
int		*ft_make_stack(char **av, t_stack *stack);

char	*concatenate_strings(char **av);
int		*convert_strings_to_integers(char *s, t_stack *stack);

void	sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);

void	ra(t_stack *stack);
void	rra(t_stack *stack);
int		rb(t_stack *stack);
int		rrb(t_stack *stack);
int		rr(t_stack *stack);
int		rrr(t_stack *stack);

int		pa(t_stack *stack);
int		pb(t_stack *stack);

void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack *stack);
void	sort_100(t_stack *stack);
void	sort_500(t_stack *stack);

void	bubble_sort(t_stack *stack);
void	stack_cpy(t_stack *stack);
int		find_maximum(t_stack *stack);
void	lol_norm_pa(t_stack *stack, int j);
void	lol_norm_pb(t_stack *stack, int j);
int		get_index(t_stack *stack, int num, int size);
int		get_index_b(t_stack *stack, int num, int size);
void	process_index(t_stack *stack, int index, int *f_range, int *s_range);

#endif
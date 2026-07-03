/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:19 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/03 18:10:49 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int is_sorted(t_stack *stack)
{
	while(stack && stack->next)
	{
		if(stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void    sort_three(t_stack **a, t_flags *flags)
{
    int first;
    int second;
    int third;

    first = (*a)->val;
    second = (*a)->next->val;
    third = (*a)->next->next->val;

	
    if (first > second && second < third && first < third)
        sa(a, flags);
    else if (first > second && second > third)
    {
        sa(a, flags);
        rra(a, flags);
    }
    else if (first > second && second < third && first > third)
        ra(a, flags);
    else if (first < second && second > third && first < third)
    {
        sa(a, flags);
        ra(a, flags);
    }
    else if (first < second && second > third && first > third)
        rra(a, flags);
}
void pick_adaptive(t_stack **a, t_stack **b, t_flags *flags, int size)
{
	float disorder;

	disorder = compute_disorder(a, flags);
	if (disorder < 0.2)
		bubble_sort(a, b, flags);
    else if (disorder < 0.5 && disorder >= 0.2)
    {
        normalize(*a, size);
        chunk_sort(a, b, flags);
    }
    else
    {
        normalize(*a, size);
        radix_sort(a, b, flags);
    }
}
//split sort into 2 more functions for a smaller size, may need another file cuz this one is hugeeee
void	handle_small_stack(t_stack **a, t_flags *flags, int size)
{
	if (size == 2)
	{
		if ((*a)->val > (*a)->next->val)
			sa(a, flags);
	}
	else if (size == 3)
		sort_three(a, flags);
}

void	dispatch_strategy(t_stack **a, t_stack **b, t_flags *flags, int size)
{
	if (flags->strategy == SIMPLE)
		bubble_sort(a, b, flags);
	else if (flags->strategy == MEDIUM || flags->strategy == COMPLEX)
		sort2(a, b, flags);
	else
		pick_adaptive(a, b, flags, size);
}
//split sort into 2 more functions for a smaller size, may need another file cuz this one is hugeeee

void	sort(t_stack **a, t_stack **b, t_flags *flags)
{
	float	disorder;
	int		size;

	disorder = compute_disorder(a, flags);
	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (flags->bench)
		print_disorder(disorder, flags);
	if (size == 2 || size == 3)
	{
		handle_small_stack(a, flags, size);
		return ;
	}
	dispatch_strategy(a, b, flags, size);
}

void sort2(t_stack **a, t_stack **b, t_flags *flags)
{
	int size;

    size = stack_size(*a);
    if (flags->strategy == MEDIUM)
    {
        normalize(*a, size);
        chunk_sort(a, b, flags);
    }
    else if (flags->strategy == COMPLEX)
    {
        normalize(*a, size);
        radix_sort(a, b, flags);
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_flags flags;
    int     start;
    int     err;

    a = NULL;
    b = NULL;
    start = parse_flags(argc, argv, &flags);
    if (start == -1)
        return (write(2, "Error\n", 6), 1);
    a = parse_args(argc, argv, start, &err);
    if (err)
        return (write(2, "Error\n", 6), free_stack(&a), 1);
    sort(&a, &b, &flags);
    free_stack(&a);
    free_stack(&b);
    return (0);
}

//parser - struct!! - ops(importante separar os writes das operacoes!!!!!!) acho q isto ja ta feito nao?
//algorithms - bench also feito?
//ver guidelines antes de submeter - PDF
//live code preparado
//só pra nao me esquecer -> cc -Wall -Werror -Wextra *.c ft_printf/*.c -I ft_printf 
//nao esquecer readme
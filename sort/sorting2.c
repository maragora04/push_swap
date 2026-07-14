/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 03:40:05 by mamendes          #+#    #+#             */
/*   Updated: 2026/07/14 03:06:17 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void pick_adaptive(t_stack **a, t_stack **b, t_flags *flags, int size)
{
	float disorder;

	disorder = compute_disorder(a);
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

void	handle_small_stack(t_stack **a, t_stack **b, t_flags *flags, int size)
{
	if (size == 2)
	{
		if ((*a)->val > (*a)->next->val)
			sa(a, flags);
	}
	else if (size == 3)
		sort_three(a, flags);
	else if (size == 4 || size == 5)
		sort_five(a, b, flags);
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

void sort(t_stack **a, t_stack **b, t_flags *flags)
{
	float	disorder;
	int		size;

	disorder = compute_disorder(a);
	size = stack_size(*a);
	if (is_sorted(*a) || size <= 1)
	{
		if (flags->bench)
			print_bench(flags, disorder);	
		return ;
	}
	if (size >= 2 && size <= 5)
		handle_small_stack(a, b, flags, size);
	else
		dispatch_strategy(a, b, flags, size);
	if (flags->bench)
		print_bench(flags, disorder);
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

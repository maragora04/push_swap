/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:45:12 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 16:45:57 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static int	sqrt_chunk(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

static void	push_chunk_to_b(t_stack **a, t_stack **b,
							int chunk_n, t_flags *flags)
{
	int	size;
	int	i;
	int	min;
	int	max;

	size = stack_size(*a);
	min = chunk_n * sqrt_chunk(size);
	max = min + sqrt_chunk(size) - 1;
	if (max >= size)
		max = size - 1;
	i = 0;
	while (i < size)
	{
		if ((*a)->val >= min && (*a)->val <= max)
			pb(a, b, flags);
		else
			ra(a, flags);
		i++;
	}
}

static int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->val;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->val > max)
		{
			max = b->val;
			pos = i;
		}
		i++;
		b = b->next;
	}
	return (pos);
}

static void	pull_b_to_a(t_stack **a, t_stack **b, t_flags *flags)
{
	int	size;
	int	pos;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_pos(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b, flags);
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b, flags);
		}
		pa(a, b, flags);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_flags *flags)
{
	int	size;
	int	chunk_n;

	size = stack_size(*a);
	chunk_n = 0;
	while (chunk_n * sqrt_chunk(size) < size)
	{
		push_chunk_to_b(a, b, chunk_n, flags);
		chunk_n++;
	}
	pull_b_to_a(a, b, flags);
}

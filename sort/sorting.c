/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 03:41:20 by mamendes          #+#    #+#             */
/*   Updated: 2026/07/17 10:54:09 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **a, t_flags *flags)
{
	int	first;
	int	second;
	int	third;

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

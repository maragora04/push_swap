/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:40:42 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/12 14:13:52 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    bubble_sort(t_stack **a, t_stack **b)
{
	int size;
	int i;
	int swapped;

	(void)b;
	size = stack_size(*a);
	while (1)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if ((*a)->val > (*a)->next->val)
			{
				sa(a);
				swapped = 1;
			}
			ra(a);
			i++;
		}
		// rotate back to original top
		i = 0;
		while (i < size - 1)
		{
			rra(a);
			i++;
		}
		if (!swapped)
			break ;
	}
}

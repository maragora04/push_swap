/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:45:57 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/11 15:45:57 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	if (!src || src->size == 0)
		return ;
	temp = src->top;
	src->top = temp->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}

void	pa(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	push(data->b, data->a);
	bench_stats->pa++;
	bench_stats->total_ops++;
	if (print)
		write (1, "pa\n", 3);
}

void	pb(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	push(data->a, data->b);
	bench_stats->pb++;
	bench_stats->total_ops++;
	if (print)
		write (1, "pb\n", 3);
}
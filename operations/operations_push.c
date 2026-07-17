/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:51:00 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 13:31:57 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*top;

	if (!*src)
		return ;
	top = *src;
	*src = (*src)->next;
	top->next = *dst;
	*dst = top;
}

void	pa(t_stack **a, t_stack **b, t_flags *flags)
{
	push(b, a);
	emit_op(flags, "pa\n", 3, OP_PA);
}

void	pb(t_stack **a, t_stack **b, t_flags *flags)
{
	push(a, b);
	emit_op(flags, "pb\n", 3, OP_PB);
}

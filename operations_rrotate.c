/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:48:35 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/30 17:16:02 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void reverse_rotate(t_stack **stack)
{
    t_stack *tail;
    t_stack *prev;

    if (!*stack || !(*stack)->next)
        return ;
    tail = *stack;
    prev = NULL;
    while (tail->next)
    {
        prev = tail;
        tail = tail->next;
    }
    prev->next = NULL;
    tail->next = *stack;
    *stack = tail;
}

void    rra(t_stack **a, t_flags *flags)
{
    reverse_rotate(a);
    emit_op(flags, "rra\n", 4, OP_RRA);
}

void    rrb(t_stack **b, t_flags *flags)
{
    reverse_rotate(b);
    emit_op(flags, "rrb\n", 4, OP_RRB);
}

void    rrr(t_stack **a, t_stack **b, t_flags *flags)
{
    reverse_rotate(a);
    reverse_rotate(b);
    emit_op(flags, "rrr\n", 4, OP_RRR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:41:49 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/19 17:45:24 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *top;
    t_stack *tail;

    if (!*stack || !(*stack)->next)
        return ;
    top = *stack;
    *stack = (*stack)->next;
    top->next = NULL;
    tail = *stack;
    while (tail->next)
        tail = tail->next;
    tail->next = top;
}


void    ra(t_stack **a, t_flags *flags)
{
    rotate(a);
    emit_op(flags, "ra\n", 3, OP_RA);
}

void    rb(t_stack **b, t_flags *flags)
{
    rotate(b);
    emit_op(flags, "rb\n", 3, OP_RB);
}

void    rr(t_stack **a, t_stack **b, t_flags *flags)
{
    rotate(a);
    rotate(b);
    emit_op(flags, "rr\n", 3, OP_RR);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:51:00 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/19 17:44:41 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_stack *top;

    if (!*src)
        return ;
    top = *src;
    *src = (*src)->next;
    top->next = *dst;
    *dst = top;
}

void    emit_op(t_flags *flags, const char *op, int len, int op_index)
{
    if (!flags || !op)
        return ;
    if (op_index >= 0 && op_index < OP_COUNT)
    {
        flags->op_count[op_index]++;
        flags->total_ops++;
    }
    if (!flags->bench)
        write(1, op, len);
}

void    pa(t_stack **a, t_stack **b, t_flags *flags)
{
    push(b, a);
    emit_op(flags, "pa\n", 3, OP_PA);
}

void    pb(t_stack **a, t_stack **b, t_flags *flags)
{
    push(a, b);
    emit_op(flags, "pb\n", 3, OP_PB);
}
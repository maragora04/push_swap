/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:51:00 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/08 03:00:45 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

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
	if (flags->bench)
    {
        flags->op_pa++;
        flags->total_ops++;
    }
    else
        ft_printf("pa\n");
}

void    pb(t_stack **a, t_stack **b, t_flags *flags)
{
    push(a, b);
    emit_op(flags, "pb\n", 3, OP_PB);
	if (flags->bench)
    {
        flags->op_pb++;
        flags->total_ops++;
    }
    else
        ft_printf("pb\n");
}

//check if its printing well 
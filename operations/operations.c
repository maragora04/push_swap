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
#include "ft_printf/ft_printf.h"

void    emit_op(t_flags *flags, const char *op, int len, int op_index)
{
    if (!flags || !op)
        return ;
    if (op_index >= 0 && op_index < OP_COUNT)
    {
        flags->op_count[op_index]++;
        flags->total_ops++;
    }
    if (!flags->bench) // && flags->strategy != COUNT
        write(1, op, len);
}

static void swap(t_stack **stack)
{
    int tmp;
    if (!*stack || !(*stack)->next)
        return ;
    tmp = (*stack)->val;
    (*stack)->val = (*stack)->next->val;
    (*stack)->next->val = tmp;
}

void    sa(t_stack **a, t_flags *flags)
{
    swap(a);
    emit_op(flags, "sa\n", 3, OP_SA);
}

void    sb(t_stack **b, t_flags *flags)
{
    swap(b);
    emit_op(flags, "sb\n", 3, OP_SB);
}

void    ss(t_stack **a, t_stack **b, t_flags *flags)
{
    swap(a);
    swap(b);
	emit_op(flags, "ss\n", 3, OP_SS);
}

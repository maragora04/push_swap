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

static void swap(t_stack **stack)
{
    int tmp;
    if (!*stack || !(*stack)->next)
        return ;
    tmp = (*stack)->val;
    (*stack)->val = (*stack)->next->val;
    (*stack)->next->val = tmp;
}

void    sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}


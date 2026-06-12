/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:48:35 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/12 11:49:18 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    rra(t_stack **a) 
{
	reverse_rotate(a); write(1, "rra\n", 4);
}

void    rrb(t_stack **b) 
{
	reverse_rotate(b); write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b) 
{
	reverse_rotate(a); reverse_rotate(b); write(1, "rrr\n", 4);
}
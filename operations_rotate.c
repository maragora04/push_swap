/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:41:49 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/12 11:42:02 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack **a)
{
    t_stack *top;
    t_stack *tail;

    if (!*a || !(*a)->next)
        return ;
    top = *a;
    *a = (*a)->next;
    top->next = NULL;
    tail = *a;
    while (tail->next)
        tail = tail->next;
    tail->next = top;
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    t_stack *top;
    t_stack *tail;

    if (!*b || !(*b)->next)
        return ;
    top = *b;
    *b = (*b)->next;
    top->next = NULL;
    tail = *b;
    while (tail->next)
        tail = tail->next;
    tail->next = top;
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    t_stack *top;
    t_stack *tail;

    if (*a && (*a)->next)
    {
        top = *a;
        *a = (*a)->next;
        top->next = NULL;
        tail = *a;
        while (tail->next)
            tail = tail->next;
        tail->next = top;
    }
    if (*b && (*b)->next)
    {
        top = *b;
        *b = (*b)->next;
        top->next = NULL;
        tail = *b;
        while (tail->next)
            tail = tail->next;
        tail->next = top;
    }
    write(1, "rr\n", 3);
}
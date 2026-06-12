/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:51:00 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/12 13:52:14 by andmigue         ###   ########.fr       */
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

void    pa(t_stack **a, t_stack **b)
{
	push(b, a); write(1, "pa\n", 3);
}
void    pb(t_stack **a, t_stack **b)
{
	push(a, b); write(1, "pb\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 02:25:52 by mamendes          #+#    #+#             */
/*   Updated: 2026/07/14 04:01:13 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static int min_pos_of(t_stack *a)
{
    int         min_pos;
    int         min_val;
    int         i;
    t_stack     *temp;

    if (!a)
        return (0);
    temp = a;
    min_pos = 0;
    min_val = temp->val;
    i = 0;
    while (temp)
    {
        if (temp->val < min_val)
        {
            min_val = temp->val;
            min_pos = i;
        }
        i++;
        temp = temp->next;
    }
    return (min_pos);
}

static void    push_min_to_b(t_stack **a, t_stack **b, t_flags *flags)
{
    int pos;
    int size;

    if (!a || !*a)
        return ;
    pos = min_pos_of(*a);
    size = stack_size(*a);
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            ra(a, flags);
            pos--;
        }
    }
    else
    {
        while (pos < size)
        {
            rra(a, flags);
            pos++;
        }
    }
    pb(a, b, flags);
}

void sort_five(t_stack **a, t_stack **b, t_flags *flags)
{
    if (!a || !*a)
        return ;
    while (stack_size(*a) > 3)
    {
        push_min_to_b(a, b, flags);
    }
    sort_three(a, flags); 
    while (*b)
    {
        pa(a, b, flags);
    }
}
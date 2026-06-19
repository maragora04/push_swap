/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:45:12 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/19 18:15:12 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  sqrt_chunk(int size)
{
    int i;

    i = 1;
    while (i * i < size)
        i++;
    return (i);
}

static void push_chunk_to_b(t_stack **a, t_stack **b, int min, int max, t_flags *flags)
{
    int size;
    int i;

    size = stack_size(*a);
    i = 0;
    while (i < size)
    {
        if ((*a)->val >= min && (*a)->val <= max)
            pb(a, b, flags);
        else
            ra(a, flags);
        i++;
    }
}

static int  find_max(t_stack *b)
{
    int max;

    max = b->val;
    while (b)
    {
        if (b->val > max)
            max = b->val;
        b = b->next;
    }
    return (max);
}

static int  pos_of(t_stack *b, int val)
{
    int pos;

    pos = 0;
    while (b->val != val)
    {
        b = b->next;
        pos++;
    }
    return (pos);
}

static void pull_b_to_a(t_stack **a, t_stack **b, t_flags *flags)
{
    int size;
    int max;
    int pos;

    while (*b)
    {
        size = stack_size(*b);
        max = find_max(*b);
        pos = pos_of(*b, max);
        if (pos <= size / 2)
        {
            while ((*b)->val != max)
                rb(b, flags);
        }
        else
        {
            while ((*b)->val != max)
                rrb(b, flags);
        }
        pa(a, b, flags);
    }
}

void    chunk_sort(t_stack **a, t_stack **b, t_flags *flags)
{
    int size;
    int chunk;
    int min;
    int max;

    size = stack_size(*a);
    chunk = sqrt_chunk(size);
    min = 0;
    while (min < size)
    {
        max = min + chunk - 1;
        if (max >= size)
            max = size - 1;
        push_chunk_to_b(a, b, min, max, flags);
        min += chunk;
    }
    pull_b_to_a(a, b, flags);
}
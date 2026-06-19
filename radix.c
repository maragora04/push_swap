/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:54:32 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/19 18:11:47 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    normalize(t_stack *a, int size)
{
    int     *ranks;
    t_stack *cur;
    t_stack *runner;
    int     rank;
    int     i;

    ranks = malloc(sizeof(int) * size);
    if (!ranks)
        return ;
    cur = a;
    i = 0;
    while (cur)
    {
        rank = 0;
        runner = a;
        while (runner)
        {
            if (runner->val < cur->val)
                rank++;
            runner = runner->next;
        }
        ranks[i++] = rank;
        cur = cur->next;
    }
    cur = a;
    i = 0;
    while (cur)
    {
        cur->val = ranks[i++];
        cur = cur->next;
    }
    free(ranks);
}

int     get_max_bits(int size)
{
    int bits;

    bits = 0;
    while ((1 << bits) <= size - 1)
        bits++;
    return (bits);
}

void    radix_sort(t_stack **a, t_stack **b, t_flags *flags)
{
    int size;
    int max_bits;
    int bit;
    int i;

    size = stack_size(*a);
    max_bits = get_max_bits(size);
    bit = 0;
    while (bit < max_bits)
    {
        i = 0;
        while (i < size)
        {
            if (((*a)->val >> bit) & 1)
                ra(a, flags);          // bit is 1 → stays in a
            else
                pb(a, b, flags);       // bit is 0 → goes to b
            i++;
        }
        while (*b)
            pa(a, b, flags);           // push everything back
        bit++;
    }
}

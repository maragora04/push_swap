/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:54:32 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/14 01:08:55 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static int  calc_rank(t_stack *a, t_stack *cur)
{
    int rank;

    rank = 0;
    while (a)
    {
        if (a->val < cur->val)
            rank++;
        a = a->next;
    }
    return (rank);
}

static void assign_ranks(t_stack *a, int *ranks, int size)
{
    int i;

    i = 0;
    while (a && i < size)
    {
        a->val = ranks[i++];
        a = a->next;
    }
}

void    normalize(t_stack *a, int size)
{
    int     *ranks;
    t_stack *cur;
    int     i;

    ranks = malloc(sizeof(int) * size);
    if (!ranks)
        return ;
    cur = a;
    i = 0;
    while (cur)
    {
        ranks[i++] = calc_rank(a, cur);
        cur = cur->next;
    }
    assign_ranks(a, ranks, size);
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
                ra(a, flags);
            else
                pb(a, b, flags);
            i++;
        }
        while (*b)
            pa(a, b, flags);
        bit++;
    }
}

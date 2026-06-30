/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:05:11 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/30 17:26:15 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

float   compute_disorder(t_stack **a, t_flags *flags)
{
    t_stack *cur;
    float   mistakes;
    float   total_pairs;

    cur = *a;
    mistakes = 0;
    total_pairs = 0;
    while (cur && cur->next)
    {
        total_pairs += 1;
        if (cur->val > cur->next->val)
            mistakes += 1;
        cur = cur->next;
    }
    if (total_pairs == 0)
        return (0.0);
    if (flags->bench)
        write(1, "benchmark mode\n", 16);
    return (mistakes / total_pairs);
}

void print_disorder(float disorder, t_flags *flags)
{
    int whole;
    int decimal;

    (void)flags;
    whole = (int)disorder;
    decimal = (int)((disorder - whole) * 100);
    if (decimal < 0)
        decimal = -decimal;
    ft_printf("disorder: %d.%d\n", whole, decimal);
}
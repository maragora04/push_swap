/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:05:11 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/06 20:34:01 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

float   compute_disorder(t_stack **a, t_flags *flags)
{
    t_stack *current;
    float   mistakes;
    float   total_pairs;

    current = *a;
    mistakes = 0;
    total_pairs = 0;
    while (current && current->next)
    {
        total_pairs += 1;
        if (current->val > current->next->val)
            mistakes += 1;
        current = current->next;
    }
    if (total_pairs == 0)
        return (0.0);
    if (flags->bench)
        write(1, "benchmark mode\n", 16);
    return (mistakes / total_pairs);
}
//this is the wrong way of doing it
void print_disorder(float disorder, t_flags *flags)
{
    int unit;
    int decimal;

    (void)flags;
    unit = (int)disorder;
    decimal = (int)((disorder - unit) * 100);
    if (decimal < 0)
        decimal = -decimal;
    ft_printf("disorder: %d.%d\n", unit, decimal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:41:41 by mamendes          #+#    #+#             */
/*   Updated: 2026/07/08 03:08:29 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

char *strategy_print(t_flags *flags)
{
    if (flags->strategy == SIMPLE)
        return ("Simple / O(n^2)");
    if (flags->strategy == MEDIUM)
        return ("Medium / O(n log n)");
    if (flags->strategy == COMPLEX)
        return ("Complex / O(n log n)");
    return ("Adaptive / O(n\xe2\x88\x9an)");
}

void print_bench(t_flags *flags, float disorder)
{
    print_disorder(disorder, flags);
    ft_printf("[bench] strategy: %s\n", strategy_print(flags));
    ft_printf("[bench] total_ops: %d\n", flags->total_ops);
    ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
        flags->op_sa, flags->op_sb, flags->op_ss, flags->op_pa, flags->op_pb);
    ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
        flags->op_ra, flags->op_rb, flags->op_rr,
        flags->op_rra, flags->op_rrb, flags->op_rrr);
}

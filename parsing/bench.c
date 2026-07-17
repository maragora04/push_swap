/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:41:41 by mamendes          #+#    #+#             */
/*   Updated: 2026/07/17 17:16:56 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

char	*strategy_print(t_flags *flags)
{
	if (flags->strategy == SIMPLE)
		return ("Simple / O(n^2)");
	if (flags->strategy == MEDIUM)
		return ("Medium / O(n\xe2\x88\x9an)");
	if (flags->strategy == COMPLEX)
		return ("Complex / O(n log n)");
	return ("Adaptive");
}

void	print_bench(t_flags *flags, float disorder)
{
	print_disorder(disorder, flags);
	ft_printf_fd(STDERR_FILENO, \
"[bench] strategy: %s\n", strategy_print(flags));
	ft_printf_fd(STDERR_FILENO, "[bench] total_ops: %d\n", flags->total_ops);
	ft_printf_fd(STDERR_FILENO, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		flags->op_count[OP_SA], flags->op_count[OP_SB], flags->op_count[OP_SS],
		flags->op_count[OP_PA], flags->op_count[OP_PB]);
	ft_printf_fd(STDERR_FILENO, "[bench] ra: %d rb: %d rr: \
%d rra: %d rrb: %d rrr: %d\n",
		flags->op_count[OP_RA], flags->op_count[OP_RB], flags->op_count[OP_RR],
		flags->op_count[OP_RRA], flags->op_count[OP_RRB],
		flags->op_count[OP_RRR]);
}

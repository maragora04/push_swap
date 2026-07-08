/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:19 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/08 03:42:49 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_flags flags;
    int     start;
    int     err;

    a = NULL;
    b = NULL;
    ft_bzero(&flags, sizeof(t_flags));
    start = parse_flags(argc, argv, &flags);
    if (start == -1)
        return (write(2, "Error\n", 6), 1);
    a = parse_args(argc, argv, start, &err);
    if (err)
        return (write(2, "Error\n", 6), free_stack(&a), 1);
    sort(&a, &b, &flags);
    free_stack(&a);
    free_stack(&b);
    return (0);
}

//parser - struct!! - ops(importante separar os writes das operacoes!!!!!!) feito
//algorithms - tbmfeito
//ver guidelines antes de submeter - PDF
//preparar live code
//nao esquecer readme
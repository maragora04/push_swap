/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:19 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/07 01:17:04 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
    t_stack	*a;
    t_stack	*b;
    t_flags	flags;
    int		start;
    int		err;

    if (argc == 1)
        return (0);
    start = parse_flags(argc, argv, &flags);
    if (start == -1)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    err = 0;
    a = parse_args(argc, argv, start, &err);
    if (err)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (!a || is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    b = NULL;
    //run algorithm based on flags.strategy
    free_stack(&a);
    free_stack(&b);
    return (0);
}
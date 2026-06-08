/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:19 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/08 14:24:20 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"


int is_sorted(t_stack *stack)
{
    while(stack && stack->next)
    {
        if(stack->val > stack->next->val)
            return (0);
        stack = stack->next;
    }
    return (1);
}
int	main(int argc, char **argv)
{
    t_stack	*a;
    t_stack	*b;
    t_flags	flags;
    int		start;
    int		err;
    int i;

    if (argc >= 2)
    {
        i = 0;
        start = set_strategy(&flags, argv[1]);
        if (start == -1)
        {
            write(2, "Error1\n", 6);
            return (1);
        }
        parse_flags(argc, &argv[i], &flags);
        err = 0;
        a = parse_args(argc, &argv[i], start, &err);
        if (err)
        {
            write(2, "Error2\n", 6);
            return (1);
        }
        if (!a || is_sorted(a))
        {
            // free_stack(&a);
            return (0);
        }
    }
    b = NULL;
    // free_stack(&a);
    // free_stack(&b);
    return (0);
}
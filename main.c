/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:19 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/15 19:27:00 by andmigue         ###   ########.fr       */
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
// int	main(int argc, char **argv)
// {
//     t_stack	*a;
//     t_stack	*b;
//     t_flags	flags;
//     int		start;
//     int		err;
//     int i;

//     if (argc >= 2)
//     {
//         i = 0;
//         start = set_strategy(&flags, argv[1]);
//         if (start == -1)
//         {
//             write(2, "Error1\n", 6);
//             return (1);
//         }
//         parse_flags(argc, &argv[i], &flags);
//         err = 0;
//         a = parse_args(argc, &argv[i], start, &err);
//         if (err)
//         {
//             write(2, "Error2\n", 6);
//             return (1);
//         }
//         if (!a || is_sorted(a))
//         {
//             // free_stack(&a);
//             return (0);
//         }
//     }
//     b = NULL;
//     // free_stack(&a);
//     // free_stack(&b);
//     return (0);
// }
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_flags flags;
    int     start;
    int     err;
    int     size;

    a = NULL;
    b = NULL;
    start = parse_flags(argc, argv, &flags);
    if (start == -1)
        return (write(2, "Error\n", 6), 1);
    a = parse_args(argc, argv, start, &err);
    if (err)
        return (write(2, "Error\n", 6), free_stack(&a), 1);
    size = stack_size(a);
	if (size == 2 && a->val > a->next->val)
		sa(&a);
	else if (size >= 3)
	{
	//	normalize(a, size);
		bubble_sort(&a, &b);
	}
    free_stack(&a);
    free_stack(&b);
    return (0);
}

//parser - struct!! - ops(importante separar os writes das operacoes!!!!!!) - 
//algorithms - bench - (opcional)libft
//ver guidelines antes de submeter - PDF
//live code preparado
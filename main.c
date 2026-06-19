/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:19 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/19 19:44:35 by andmigue         ###   ########.fr       */
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
void    sort_three(t_stack **a, t_flags *flags)
{
    int first;
    int second;
    int third;

    first = (*a)->val;
    second = (*a)->next->val;
    third = (*a)->next->next->val;
    if (first > second && second < third && first < third)
        sa(a, flags);
    else if (first > second && second > third)
    {
        sa(a, flags);
        rra(a, flags);
    }
    else if (first > second && second < third && first > third)
        ra(a, flags);
    else if (first < second && second > third && first < third)
    {
        sa(a, flags);
        ra(a, flags);
    }
    else if (first < second && second > third && first > third)
        rra(a, flags);
}
static void pick_adaptive(t_stack **a, t_stack **b, t_flags *flags, int size)
{
    if (size <= 100)
    {
        normalize(*a, size);
        chunk_sort(a, b, flags);     // chunk is great for small-mid size
    }
    else
    {
        normalize(*a, size);
        radix_sort(a, b, flags);     // radix scales better for large size
    }
}

void    sort(t_stack **a, t_stack **b, t_flags *flags)
{
    int size;

    size = stack_size(*a);
    if (size <= 1)
        return ;
    if (size == 2)
    {
        if ((*a)->val > (*a)->next->val)
            sa(a, flags);
        return ;
    }
    if (size == 3)
    {
        sort_three(a, flags);
        return ;
    }
    if (flags->strategy == SIMPLE)
        bubble_sort(a, b, flags);
    else if (flags->strategy == MEDIUM)
    {
        normalize(*a, size);
        chunk_sort(a, b, flags);
    }
    else if (flags->strategy == COMPLEX)
    {
        normalize(*a, size);
        radix_sort(a, b, flags);
    }
    else
        pick_adaptive(a, b, flags, size);
}



int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_flags flags;
    int     start;
    int     err;

    a = NULL;
    b = NULL;
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

//parser - struct!! - ops(importante separar os writes das operacoes!!!!!!) - 
//algorithms - bench - (opcional)libft
//ver guidelines antes de submeter - PDF
//live code preparado


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

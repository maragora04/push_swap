/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:57:10 by mamendes          #+#    #+#             */
/*   Updated: 2026/06/07 01:14:40 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_flags
{
    int strategy;
    int bench;
}   t_flags;

typedef struct s_stack
{
    int             val;
    struct s_stack  *next;
}   t_stack;

#endif
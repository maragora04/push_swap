/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:56:51 by mamendes          #+#    #+#             */
/*   Updated: 2026/06/06 20:59:38 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **stack, int val)
{
    t_stack	*new;
    t_stack	*tmp;

    new = malloc(sizeof(t_stack));
    if (!new)
        return ;
    new->val = val;
    new->next = NULL;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void	free_stack(t_stack **stack)
{
    t_stack	*tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

void	free_tokens(char **tokens)
{
    int	i;

    if (!tokens)
        return ;
    i = 0;
    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
}
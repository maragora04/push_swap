/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:04:47 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 11:05:20 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_single_str(t_stack **stack, char *str)
{
	char	**tokens;
	int		i;

	if (!str || !str[0])
		return (0);
	tokens = ft_split(str, ' ');
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens);
		return (0);
	}
	i = 0;
	while (tokens[i])
	{
		if (!validate_and_push(stack, tokens[i]))
		{
			free_tokens(tokens);
			return (0);
		}
		i++;
	}
	free_tokens(tokens);
	return (1);
}

int	has_duplicate(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	validate_and_push(t_stack **stack, char *str)
{
	int	val;
	int	err;

	if (!is_valid_number(str))
		return (0);
	err = 0;
	val = ft_atoi_safe(str, &err);
	if (err || has_duplicate(*stack, val))
		return (0);
	stack_add_back(stack, val);
	return (1);
}

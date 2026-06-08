/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:12:27 by mamendes          #+#    #+#             */
/*   Updated: 2026/06/08 12:25:55 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (EXIT_FAILURE);
}

int	ft_atoi_safe(char *str, int *err)
{
	long	res;
	int		sign;
	int		i;

	*err = 0;
	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res > 2147483648)
		{
			*err = 1;
			return (0);
		}
		i++;
	}
	return ((int)(res * sign));
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

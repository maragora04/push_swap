/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:53:11 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 18:29:19 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	set_strategy(t_flags *flags, char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		if (flags->bench == 1)
			return (0);
		return (flags->bench = 1, 1);
	}
	if (flags->strategy != -1)
		return (0);
	if (ft_strcmp(arg, "--simple") == 0)
		flags->strategy = SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		flags->strategy = MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		flags->strategy = COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		flags->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	flags->strategy = -1;
	flags->bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!set_strategy(flags, argv[i]))
			return (-1);
		i++;
	}
	if (flags->strategy == -1)
		flags->strategy = ADAPTIVE;
	return (i);
}

t_stack	*parse_multiple(int argc, char **argv, int start, int *err)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = start;
	while (i < argc)
	{
		if (!parse_single_str(&stack, argv[i]))
		{
			*err = 1;
			free_stack(&stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

t_stack	*parse_args(int argc, char **argv, int start, int *err)
{
	*err = 0;
	if (start >= argc)
		return (NULL);
	return (parse_multiple(argc, argv, start, err));
}

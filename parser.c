/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:59:42 by mamendes          #+#    #+#             */
/*   Updated: 2026/06/07 01:16:29 by mamendes         ###   ########.fr       */
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
static int	set_strategy(t_flags *flags, char *arg)
{
    if (ft_strcmp(arg, "--simple") == 0)
        flags->strategy = SIMPLE;
    else if (ft_strcmp(arg, "--medium") == 0)
        flags->strategy = MEDIUM;
    else if (ft_strcmp(arg, "--complex") == 0)
        flags->strategy = COMPLEX;
    else if (ft_strcmp(arg, "--adaptive") == 0)
        flags->strategy = ADAPTIVE;
    else if (ft_strcmp(arg, "--bench") == 0)
        flags->bench = 1;
    else
        return (0);
    return (1);
}

// returns index of first number arg, or -1 on unknown flag 
int	parse_flags(int argc, char **argv, t_flags *flags)
{
    int	i;

    flags->strategy = ADAPTIVE;
    flags->bench = 0;
    i = 1;
    while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
    {
        if (!set_strategy(flags, argv[i]))
            return (-1);
        i++;
    }
    return (i);
}

static int	parse_single_str(t_stack **stack, char *str)
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
static t_stack	*parse_multiple(int argc, char **argv, int start, int *err)
{
    t_stack	*stack;
    int		i;

    stack = NULL;
    i = start;
    while (i < argc)
    {
        if (!validate_and_push(&stack, argv[i++]))
        {
            *err = 1;
            free_stack(&stack);
            return (NULL);
        }
    }
    return (stack);
}

t_stack	*parse_args(int argc, char **argv, int start, int *err)
{
    t_stack	*stack;

    *err = 0;
    stack = NULL;
    if (start >= argc)
        return (NULL);
    if (start == argc - 1 && ft_strchr(argv[start], ' '))
    {
        if (!parse_single_str(&stack, argv[start]))
        {
            *err = 1;
            free_stack(&stack);
            return (NULL);
        }
        return (stack);
    }
    return (parse_multiple(argc, argv, start, err));
}
void *pushswap_parsing(char *str, char **av, int ac)
{
	int i;

	i = 0;
	if (ac > 2)
	{
		if (!is_valid_number(av[i]))
		{
    		ft_printf("Error\n", 2);
    		exit(EXIT_FAILURE);
		}
	}
	else
		exit(EXIT_SUCCESS);
}


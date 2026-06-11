/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:57:10 by mamendes          #+#    #+#             */
/*   Updated: 2026/06/11 17:46:29 by andmigue         ###   ########.fr       */
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

int             ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int	    set_strategy(t_flags *flags, char *arg);
int             parse_flags(int argc, char **argv, t_flags *flags);
int	    parse_single_str(t_stack **stack, char *str);
t_stack	*parse_multiple(int argc, char **argv, int start, int *err);
t_stack	        *parse_args(int argc, char **argv, int start, int *err);

int	is_valid_number(char *str);
int	ft_atoi_safe(char *str, int *err);
int	has_duplicate(t_stack *stack, int val);
int	validate_and_push(t_stack **stack, char *str);

void	stack_add_back(t_stack **stack, int val);
void	free_stack(t_stack **stack);
void	free_tokens(char **tokens);

#endif
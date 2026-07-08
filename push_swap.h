/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:57:10 by mamendes          #+#    #+#             */
/*   Updated: 2026/07/08 03:14:40 by mamendes         ###   ########.fr       */
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

enum e_op
{
    OP_SA,
    OP_SB,
    OP_SS,
    OP_PA,
    OP_PB,
    OP_RA,
    OP_RB,
    OP_RR,
    OP_RRA,
    OP_RRB,
    OP_RRR,
    OP_COUNT  
};
// total number of ops, used for array size
typedef struct s_flags
{
    int strategy;
    int bench;
    int op_count[OP_COUNT];
	int op_sa, op_sb, op_ss, op_pa, op_pb;
	int op_ra, op_rb, op_rr, op_rra, op_rrb, op_rrr;
    int total_ops;
}   t_flags;

typedef struct s_stack
{
	int             val;
	struct s_stack  *next;
}   t_stack;


int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		set_strategy(t_flags *flags, char *arg);
int		parse_flags(int argc, char **argv, t_flags *flags);
int		parse_single_str(t_stack **stack, char *str);
t_stack	*parse_multiple(int argc, char **argv, int start, int *err);
t_stack	*parse_args(int argc, char **argv, int start, int *err);

int		is_valid_number(char *str);
int		ft_atoi_safe(char *str, int *err);
int		has_duplicate(t_stack *stack, int val);
int		validate_and_push(t_stack **stack, char *str);

void	stack_add_back(t_stack **stack, int val);
void	free_stack(t_stack **stack);
void	free_tokens(char **tokens);
int		stack_size(t_stack *a);

void    sa(t_stack **a, t_flags *flags);
void    sb(t_stack **b, t_flags *flags);
void    ss(t_stack **a, t_stack **b, t_flags *flags);
void    pa(t_stack **a, t_stack **b, t_flags *flags);
void    pb(t_stack **a, t_stack **b, t_flags *flags);
void    ra(t_stack **a, t_flags *flags);
void    rb(t_stack **b, t_flags *flags);
void    rr(t_stack **a, t_stack **b, t_flags *flags);
void    rra(t_stack **a, t_flags *flags);
void    rrb(t_stack **b, t_flags *flags);
void    rrr(t_stack **a, t_stack **b, t_flags *flags);
void    emit_op(t_flags *flags, const char *op, int len, int op_index);

void    sort_three(t_stack **a, t_flags *flags);

void    bubble_sort(t_stack **a, t_stack **b, t_flags *flags);

void    radix_sort(t_stack **a, t_stack **b, t_flags *flags);
int     get_max_bits(int size);
void    normalize(t_stack *a, int size);

void    chunk_sort(t_stack **a, t_stack **b, t_flags *flags);

void    sort(t_stack **a, t_stack **b, t_flags *flags);
void    sort2(t_stack **a, t_stack **b, t_flags *flags);
float   compute_disorder(t_stack **a);
void	print_disorder(float disorder, t_flags *flags);
void	dispatch_strategy(t_stack **a, t_stack **b, t_flags *flags, int size);
void	handle_small_stack(t_stack **a, t_flags *flags, int size);
void 	print_bench(t_flags *flags, float disorder);
char 	*strategy_print(t_flags *flags);


#endif
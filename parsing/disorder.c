/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:05:11 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 13:34:04 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

float	compute_disorder(t_stack **a)
{
	t_stack	*current;
	float	mistakes;
	float	total_pairs;

	current = *a;
	mistakes = 0;
	total_pairs = 0;
	while (current && current->next)
	{
		total_pairs += 1;
		if (current->val > current->next->val)
			mistakes += 1;
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

void	print_disorder(float disorder, t_flags *flags)
{
	float	percent;
	int		unit;
	int		decimal;

	(void)flags;
	percent = disorder * 100;
	unit = (int)percent;
	decimal = (int)((percent - unit) * 100 + 0.5);
	if (decimal == 100)
	{
		decimal = 0;
		unit++;
	}
	if (decimal < 10)
		ft_printf("[bench] disorder: %d.0%d%%\n", unit, decimal);
	else
		ft_printf("[bench] disorder: %d.%d%%\n", unit, decimal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:03:28 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/11 16:31:49 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	best_way(t_stack *stack, int nb)
{
	int	top;
	int	bottom;

	top = stack->size - 1;
	bottom = 0;
	while (stack->tab[top] != nb)
		top--;
	while (stack->tab[bottom] != nb)
		bottom++;
	if (stack->size - top > bottom)
		return (bottom);
	return (top);
}

int	next_in_b(t_stack *stack)
{
	int	nb;
	int	count;

	nb = 0;
	count = 0;
	while (count < stack->size)
	{
		if (stack->tab[count] > nb)
			nb = stack->tab[count];
		count++;
	}
	return (nb);
}

int	next_in_a(t_stack *a)
{
	int	i;
	int	med;
	int	j;

	i = 0;
	med = a->size / 2;
	j = a->size - 1;
	while ((a->tab[i] <= med - a->ch && a->tab[i] >= med + a->ch))
		i++;
	while ((a->tab[j] <= med - a->ch && a->tab[j] >= med + a->ch))
		j--;
	if (a->size - j - 1 > i)
		return (2);
	else
		return (1);
}

int	number_is_in_range(t_stack *stack)
{
	int	count;

	count = 0;
	while (count < stack->size)
	{
		if (stack->tab[count] < (stack->len / 2 + stack->ch)
			&& stack->tab[count] > (stack->len / 2 - stack->ch))
			return (1);
		count++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:45:46 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/11 16:25:21 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_to_b(t_stack *a, t_stack *b)
{
	int	med;

	med = a->size / 2;
	while (a->size)
	{
		if (number_is_in_range(a))
		{
			if ((a->tab[a->size - 1] >= med - a->ch && a->tab[a->size
						- 1] <= med + a->ch))
			{
				push_to_stack(pop_from_stack(a), b);
				if (b->tab[b->size - 1] < med)
					rotate(b);
			}
			else
			{
				if (next_in_a(a) == 1)
					rotate(a);
				else
					rotate_reverse(a);
			}
		}
		else
			a->ch += a->chunk;
	}
}

static void	case_b(t_stack *b, int count, int next)
{
	count = best_way(b, next);
	while (b->tab[b->size - 1] != next)
	{
		if (count > b->size / 2)
			rotate(b);
		else
			rotate_reverse(b);
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	next;
	int	count;

	next = 0;
	count = 0;
	while (b->size)
	{
		next = next_in_b(b);
		if (b->tab[b->size - 1] == next || b->tab[b->size - 1] == next - 1)
		{
			push_to_stack(pop_from_stack(b), a);
			if (a->tab[a->size - 1] > a->tab[a->size - 2])
				swap(a);
		}
		else
		{
			case_b(b, count, next);
		}
	}
}

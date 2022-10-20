/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:44:16 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/11 16:29:11 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_one(t_stack *a, t_stack *b)
{
	rotate_reverse(a);
	push_to_stack(pop_from_stack(b), a);
	rotate(a);
	rotate(a);
}

static void	case_two(t_stack *a, t_stack *b)
{
	rotate(a);
	push_to_stack(pop_from_stack(b), a);
	swap(a);
	rotate_reverse(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (b->tab[b->size - 1] < a->tab[a->size - 1])
		push_to_stack(pop_from_stack(b), a);
	else if (b->tab[b->size - 1] > a->tab[0])
	{
		push_to_stack(pop_from_stack(b), a);
		rotate(a);
	}
	else if (b->tab[b->size - 1] > a->tab[a->size - 1] && b->tab[b->size
			- 1] < a->tab[a->size - 2])
	{
		push_to_stack(pop_from_stack(b), a);
		swap(a);
	}
	else if (b->tab[b->size - 1] < a->tab[0] && b->tab[b->size - 1] > a->tab[1])
		case_one(a, b);
	else if (b->tab[b->size - 1] < a->tab[1] && b->tab[b->size
			- 1] > a->tab[a->size - 2])
		case_two(a, b);
}

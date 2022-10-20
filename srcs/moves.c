/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:21:11 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/11 18:43:48 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_stack(int nb, t_stack *stack)
{
	stack->tab[stack->size] = nb;
	stack->size++;
	stack->ops++;
	printf("p%c\n", stack->name);
}

int	pop_from_stack(t_stack *stack)
{
	int	val;

	if (stack->size >= 1)
	{
		val = stack->tab[stack->size - 1];
		stack->tab[stack->size - 1] = 0;
		stack->size--;
		return (val);
	}
	return (0);
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->tab[stack->size - 1];
		stack->tab[stack->size - 1] = stack->tab[stack->size - 2];
		stack->tab[stack->size - 2] = tmp;
		stack->ops++;
		printf("s%c\n", stack->name);
	}
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size >= 2)
	{
		tmp = stack->tab[stack->size - 1];
		i = stack->size;
		while (i--)
			stack->tab[i] = stack->tab[i - 1];
		stack->tab[0] = tmp;
		stack->ops++;
		printf("r%c\n", stack->name);
	}
}

void	rotate_reverse(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size >= 2)
	{
		i = 0;
		tmp = stack->tab[i];
		while (stack->tab[i++])
			stack->tab[i - 1] = stack->tab[i];
		stack->tab[stack->size - 1] = tmp;
		printf("rr%c\n", stack->name);
		stack->ops++;
	}
}

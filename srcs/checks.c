/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:59:21 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/12 13:24:33 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	only_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' '
					|| argv[i][j] == '-'))
				return (0);
			else if (argv[i][j] == '-' && !(argv[i][j + 1] >= '0' && argv[i][j
						+ 1] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	max_value(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->tab[i++])
	{
		if (stack->tab[i] > INT_MAX || stack->tab[i] < INT_MIN)
			return (0);
	}
	return (1);
}

int	no_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack->tab[i])
	{
		j = i + 1;
		while (stack->tab[j])
		{
			if (stack->tab[i] == stack->tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	not_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->tab[i] && stack->tab[i + 1])
	{
		if (stack->tab[i] < stack->tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	already_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->tab[i] && stack->tab[i + 1])
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

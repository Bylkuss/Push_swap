/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:19:02 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/11 17:19:05 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stars(int nb)
{
	while (nb--)
		printf("*");
	printf("\n");
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->size;
	printf("\n%sPrinting Stack->%c: \n", BGRN, stack->name);
	printf("Stack->%c size: %d\n", stack->name, stack->size);
	while (i--)
	{
		printf("%c.tab[%d]: %d ", stack->name, i, stack->tab[i]);
		print_stars(stack->tab[i]);
	}
}

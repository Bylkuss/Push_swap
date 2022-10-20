/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:27:18 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/12 13:25:57 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack *stack)
{
	if ((stack->tab[0] > stack->tab[1] && stack->tab[1] < stack->tab[2]
			&& stack->tab[0] > stack->tab[2]))
		swap(stack);
	else if (stack->tab[0] < stack->tab[1] && stack->tab[1] < stack->tab[2]
		&& stack->tab[2] > stack->tab[0])
	{
		swap(stack);
		rotate_reverse(stack);
	}
	else if (stack->tab[0] > stack->tab[1] && stack->tab[2] > stack->tab[1]
		&& stack->tab[0] < stack->tab[2])
		rotate(stack);
	else if (stack->tab[2] < stack->tab[1] && stack->tab[1] > stack->tab[0]
		&& stack->tab[0] > stack->tab[2])
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->tab[0] < stack->tab[1] && stack->tab[2] < stack->tab[1]
		&& stack->tab[0] < stack->tab[2])
		rotate_reverse(stack);
}

void	ft_store(char **argv, t_stack *stack, int args_nb)
{
	int	i;

	i = 0;
	while (args_nb--)
	{
		if (ft_atol(argv[args_nb]) <= INT_MAX
			&& ft_atol(argv[args_nb]) >= INT_MIN)
		{
			stack->tab[i] = indexing(ft_atol(argv[args_nb]), argv);
			stack->size++;
			i++;
		}
		else
		{
			if (stack->free_flag == 1)
				free_tab(argv);
			free(stack->tab);
			exit_msg("Error\n", EXIT_FAILURE);
		}
	}
}

void	push_swap(t_stack *a, t_stack *b, int args_nb)
{
	if (args_nb <= 3)
		sort_three(a);
	else if (args_nb <= 5)
	{
		a->len = a->size;
		while (a->size > 3)
			push_to_stack(pop_from_stack(a), b);
		sort_three(a);
		while (a->size < a->len)
			sort_five(a, b);
	}
	else
	{
		a_to_b(a, b);
		b_to_a(a, b);
	}
}

void	init_struct(t_stack *a, t_stack *b, int args_nb)
{
	a->size = 0;
	a->name = 'a';
	b->name = 'b';
	b->size = 0;
	a->ops = 0;
	b->ops = 0;
	a->ch = 15;
	if (args_nb >= 250)
		a->ch = 27;
	a->med = a->size / 2;
	a->chunk = a->ch;
	a->tab = malloc(sizeof(int) * args_nb);
	b->tab = malloc(sizeof(int) * args_nb);
	if (!a->tab || !b->tab)
		exit(0);
}

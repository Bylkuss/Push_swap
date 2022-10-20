/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:13:32 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/12 13:25:15 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_args(int argc, char **argv, t_stack *a)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		a->free_flag = 1;
	}
	else
		args = &argv[1];
	return (args);
}

static void	check_free_exit(t_stack *a, t_stack *b, char **args)
{
	a->len = a->size;
	if (!only_digits(args) || !no_doubles(a))
	{
		if (a->free_flag == 1)
			free_tab(args);
		ft_putstr_fd("Error\n", 2);
		free(a->tab);
		free(b->tab);
		exit(EXIT_FAILURE);
	}
}

static void	check_shit(char *argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if ((argv[j] >= '0' && argv[j] <= '9') || argv[j + 1] == ' ')
		{
			if (argv[++j] == ' ')
			{
				while (argv[j] == ' ')
					j++;
				if (argv[j] >= '0' && argv[j] <= '9')
					exit_msg("Error\n", 0);
			}
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		args_nb;

	a.free_flag = 0;
	if (argc >= 2 && argv[1])
	{
		if (argv[2])
			check_shit(argv[2]);
		args = get_args(argc, argv, &a);
		args_nb = tablen(args);
		init_struct(&a, &b, args_nb);
		ft_store(args, &a, args_nb);
		check_free_exit(&a, &b, args);
		if (not_sorted(&a))
			push_swap(&a, &b, args_nb);
		if (a.free_flag == 1)
			free_tab(args);
		free(a.tab);
		free(b.tab);
		exit(0);
	}
	return (0);
}

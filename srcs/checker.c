/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:11:26 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/12 13:24:52 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_get_next_line(int fd)
{
	char	*str;
	char	*buff;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 5);
	buff = str;
	while (read(fd, buff, 1) > 0 && *buff++ != '\n')
		i++;
	if (buff > str)
	{
		buff = 0;
		return (str);
	}
	else
	{
		free(str);
		return (0);
	}
}

void	apply_moves(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		push_to_stack(pop_from_stack(b), a);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push_to_stack(pop_from_stack(a), b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		rotate_reverse(a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		rotate_reverse(b);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap(b);
	else
		exit_msg("Error\n", EXIT_FAILURE);
}

void	ft_checker(t_stack *a, t_stack *b)
{
	char	*move;

	move = ft_get_next_line(0);
	while (move)
	{
		apply_moves(a, b, move);
		free(move);
		move = ft_get_next_line(0);
	}
	if (already_sorted(a) == 1 && !b->size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	free(move);
}

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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		args_nb;
	int		flag;

	flag = 0;
	if (argc > 2)
	{
		args = get_args(argc, argv, &a);
		args_nb = tablen(args);
		init_struct(&a, &b, args_nb);
		ft_store(args, &a, args_nb);
		ft_checker(&a, &b);
		if (flag == 1)
			free_tab(args);
		free(a.tab);
		free(b.tab);
	}
	return (0);
}

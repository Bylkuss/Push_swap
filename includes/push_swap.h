/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:29:32 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/12 13:27:37 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ******COLORS****** */
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

typedef struct s_stack
{
	int		size;
	int		len;
	int		index;
	char	name;
	int		*tab;
	int		ch;
	int		chunk;
	int		free_flag;
	int		med;
	int		ops;
}			t_stack;

/* ******CHECKS****** */
int			only_digits(char **argv);
int			no_doubles(t_stack *stack);
int			max_value(t_stack *stack);
int			not_sorted(t_stack *stack);
int			already_sorted(t_stack *stack);

/* ******PUSH_SWAP****** */

void		push_swap(t_stack *a, t_stack *b, int args_nb);
// void		sort_three(t_stack *stack);
void		sort_five(t_stack *a, t_stack *b);

/* ******UTILS****** */
void		exit_msg_free(char *msg, int exiit, int *to_free);
void		exit_msg(char *msg, int exiit);
void		free_tab(char **tab);
long		ft_atol(char *str);
int			indexing(long nb, char **argv);
void		ft_store(char **argv, t_stack *stack, int args_nb);
int			tablen(char **tab);

/* ******LOGS****** */
void		print_stack(t_stack *stack);

/* ******MOVES****** */
void		push_to_stack(int nb, t_stack *stack);
int			pop_from_stack(t_stack *stack);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rotate_reverse(t_stack *stack);

/* ******RADIX_SORT****** */
void		first_push(t_stack *a, t_stack *b);
void		push_back(t_stack *a, t_stack *b, int args_nb);

/* ******BIG_ALGO****** */
void		a_to_b(t_stack *a, t_stack *b);
void		b_to_a(t_stack *a, t_stack *b);

/* ******UTILS_BIG_ALGO****** */
int			next_in_a(t_stack *a);
int			next_in_b(t_stack *stack);
int			best_way(t_stack *stack, int nb);
int			number_is_in_range(t_stack *stack);
/**********MAIN.C********/
char		**get_args(int argc, char **argv, t_stack *a);
void		init_struct(t_stack *a, t_stack *b, int args_nb);

#endif

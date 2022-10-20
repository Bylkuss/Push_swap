/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:01:49 by loadjou           #+#    #+#             */
/*   Updated: 2022/10/11 20:48:55 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg(char *msg, int exiit)
{
	ft_putstr_fd(msg, 2);
	exit(exiit);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	indexing(long nb, char **argv)
{
	int	index;
	int	i;

	index = 1;
	i = 0;
	while (argv[i])
	{
		if (nb > ft_atol(argv[i]))
			index++;
		i++;
	}
	return (index);
}

int	tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
	{
		len++;
	}
	return (len);
}

long	ft_atol(char *str)
{
	long			i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

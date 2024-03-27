/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_helpers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:37 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:17:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static long	ft_atol(char *number)
{
	long	long_num;
	int		neg;
	int		i;

	i = 0;
	neg = 1;
	long_num = 0;
	if (number[i] == '-' || number[i] == '+')
		if (number[i++] == '-')
			neg = -1;
	while (number[i])
		long_num = long_num * 10 + (number[i++] - '0');
	long_num *= neg;
	return (long_num);
}

static int	is_number(char *argument)
{
	int	i;

	i = 0;
	if (argument[i] == '-' || argument[i] == '+')
		i++;
	while (argument[i] && argument[i] == '0')
		i++;
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int(char *number)
{
	long	long_num;
	int		num_len;
	int		i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] && number[i] == '0')
		i++;
	num_len = ft_strlen(&number[i]);
	long_num = ft_atol(number);
	if (num_len > MAX_ARG_LENGTH || long_num < INT_MIN || long_num > INT_MAX)
		return (0);
	return (1);
}

static int	is_dup(char *number, char **argv)
{
	int		i;
	int		num_count;
	int		int_num;

	i = 0;
	num_count = 0;
	int_num = ft_atoi(number);
	while (argv[i])
	{
		if (int_num == ft_atoi(argv[i]))
			num_count++;
		if (num_count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_args_validity(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]) || !is_int(argv[i]) || is_dup(argv[i], argv))
			return (0);
		i++;
	}
	return (1);
}

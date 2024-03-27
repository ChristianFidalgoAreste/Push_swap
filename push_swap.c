/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:54:12 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 16:27:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 2)
		return (0);
	if (!check_args_validity(&argv[1])
		|| !init_state(&state, argc - 1, &argv[1]))
		handle_error();
	if (!is_stack_sorted(state.stack_a))
		sort_stack(&state);
	return (clear_state(&state), 0);
}

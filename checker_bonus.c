/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:50:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 21:11:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_stack_sorted(t_stack *stack)
{
	int			i;
	int			last_num;
	t_element	*element;

	i = 0;
	last_num = stack->top_element->num;
	element = stack->top_element->next;
	if (stack->size == 1)
		return (1);
	while (i < stack->size - 1 && element)
	{
		if (element->num < last_num)
			return (0);
		last_num = element->num;
		element = element->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 2)
		return (0);
	if (!check_args_validity(&argv[1])
		|| !init_state(&state, argc - 1, &argv[1]))
		handle_error();
	read_instructions(&state);
	if (is_stack_sorted(state.stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (clear_state(&state), 0);
}

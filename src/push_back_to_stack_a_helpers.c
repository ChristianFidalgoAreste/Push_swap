/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_stack_a_helpers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:32 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 16:43:34 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_num_index_in_stack_a(t_state *state, int stack_b_num)
{
	int			i;
	t_element	*top_element;
	t_element	*prev_element;

	i = 0;
	top_element = state->stack_a->top_element;
	prev_element = top_element->prev;
	while (prev_element->num > stack_b_num || top_element->num < stack_b_num)
	{
		prev_element = top_element;
		top_element = top_element->next;
		i++;
	}
	return (i);
}

int	find_smallest_num_index_in_stack_a(t_state *state)
{
	int			i;
	t_element	*top_element;

	i = 0;
	top_element = state->stack_a->top_element;
	while (top_element->num != state->stack_a->smallest)
	{
		top_element = top_element->next;
		i++;
	}
	return (i);
}

void	calculate_prerotations_stack_a(t_state *state, int num_index)
{
	if (num_index <= state->stack_a->size / 2)
		state->moves->ra = num_index;
	else
		state->moves->rra = state->stack_a->size - num_index;
}

void	arrange_stack_a(t_state *state)
{
	int			smallest_num_index;
	t_element	*top_element;

	top_element = state->stack_a->top_element;
	smallest_num_index = find_smallest_num_index_in_stack_a(state);
	calculate_prerotations_stack_a(state, smallest_num_index);
	execute_moves(state);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:14:12 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 19:25:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_num_index_in_stack_b(t_state *state, int stack_a_num)
{
	int			i;
	t_element	*top_element;
	t_element	*prev_element;

	i = 0;
	top_element = state->stack_b->top_element;
	prev_element = top_element->prev;
	while (prev_element->num < stack_a_num || top_element->num > stack_a_num)
	{
		prev_element = top_element;
		top_element = top_element->next;
		i++;
	}
	return (i);
}

int	find_biggest_num_index_in_stack_b(t_state *state)
{
	int			i;
	t_element	*top_element;

	i = 0;
	top_element = state->stack_b->top_element;
	while (top_element->num != state->stack_b->biggest)
	{
		top_element = top_element->next;
		i++;
	}
	return (i);
}

static int	find_num_index_in_stack_a(t_state *state, int num)
{
	int			i;
	t_element	*top_element;

	i = 0;
	top_element = state->stack_a->top_element;
	while (top_element->num != num)
	{
		top_element = top_element->next;
		i++;
	}
	return (i);
}

void	calculate_prerotations_stack_b(t_state *state, int num_index)
{
	if (num_index <= state->stack_b->size / 2)
		state->moves->rb = num_index;
	else
		state->moves->rrb = state->stack_b->size - num_index;
}

void	calculate_rotations_stack_a(t_state *state, int num_to_move)
{
	int	num_index;

	num_index = find_num_index_in_stack_a(state, num_to_move);
	calculate_prerotations_stack_a(state, num_index);
}

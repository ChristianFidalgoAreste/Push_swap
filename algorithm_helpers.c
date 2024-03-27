/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:54:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:51:01 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
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

static int	find_num_index_in_stack_b(t_state *state, int num_to_move)
{
	int	next_num_index;

	if (num_to_move < state->stack_b->smallest
		|| num_to_move > state->stack_b->biggest)
		next_num_index = find_biggest_num_index_in_stack_b(state);
	else
		next_num_index = find_next_num_index_in_stack_b(state, num_to_move);
	return (next_num_index);
}

static void	calculate_cheapest_number(t_state *state)
{
	int			i;
	int			num_index;
	int			new_move_cost;
	t_element	*element;

	i = 0;
	state->move_cost = state->argc;
	element = state->stack_a->top_element;
	state->min_move_cost_num = element->num;
	while (state->move_cost > 1 && i < state->stack_a->size)
	{
		num_index = find_num_index_in_stack_b(state, element->num);
		calculate_rotations_stack_a(state, element->num);
		calculate_prerotations_stack_b(state, num_index);
		calculate_double_rotations(state);
		new_move_cost = calculate_move_cost(state);
		if (state->move_cost > new_move_cost || i == 0)
		{
			state->min_move_cost_num = element->num;
			state->move_cost = new_move_cost;
		}
		reset_moves(state->moves);
		element = element->next;
		i++;
	}
}

void	push_to_stack_b(t_state *state)
{
	int	top_a_num;
	int	next_num_index;

	while (state->stack_a->size > MIN_NUMBERS_TO_SORT)
	{
		calculate_cheapest_number(state);
		top_a_num = state->min_move_cost_num;
		next_num_index = find_num_index_in_stack_b(state, top_a_num);
		calculate_rotations_stack_a(state, top_a_num);
		calculate_prerotations_stack_b(state, next_num_index);
		calculate_double_rotations(state);
		execute_moves(state);
		push_b(state);
	}
}

void	push_back_to_stack_a(t_state *state)
{
	int	top_b_num;
	int	next_num_index;

	while (state->stack_b->size > 0)
	{
		top_b_num = state->stack_b->top_element->num;
		if (top_b_num < state->stack_a->smallest
			|| top_b_num > state->stack_a->biggest)
			next_num_index = find_smallest_num_index_in_stack_a(state);
		else
			next_num_index = find_next_num_index_in_stack_a(state, top_b_num);
		calculate_prerotations_stack_a(state, next_num_index);
		execute_moves(state);
		push_a(state);
	}
	arrange_stack_a(state);
}

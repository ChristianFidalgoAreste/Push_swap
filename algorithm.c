/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:45:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 17:23:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_elements_stack(t_state *state)
{
	t_element	*element;

	element = state->stack_a->top_element;
	if (element->num > element->next->num)
		swap_a(state);
}

static void	sort_three_elements_stack(t_state *state)
{
	int	first_number;
	int	second_number;
	int	third_number;

	if (is_stack_sorted(state->stack_a))
		return ;
	first_number = state->stack_a->top_element->num;
	second_number = state->stack_a->top_element->next->num;
	third_number = state->stack_a->top_element->prev->num;
	if (first_number < second_number && first_number > third_number)
		return (rev_rotate_a(state));
	if (first_number > second_number && first_number < third_number)
		return (swap_a(state));
	if (first_number > second_number && first_number > third_number
		&& second_number < third_number)
		return (rotate_a(state));
	swap_a(state);
	sort_three_elements_stack(state);
}

static void	sort_four_elements_stack(t_state *state)
{
	int	top_b_num;
	int	top_a_number;
	int	second_number;
	int	last_number;

	push_b(state);
	sort_three_elements_stack(state);
	if (state->stack_b->smallest < state->stack_a->smallest)
		return (push_a(state));
	if (state->stack_b->biggest > state->stack_a->biggest)
		return (push_a(state), rotate_a(state));
	top_b_num = state->stack_b->top_element->num;
	top_a_number = state->stack_a->top_element->num;
	second_number = state->stack_a->top_element->next->num;
	last_number = state->stack_a->top_element->prev->num;
	if (top_b_num > top_a_number && top_b_num < second_number)
		return (push_a(state), swap_a(state));
	rev_rotate_a(state);
	push_a(state);
	rotate_a(state);
	rotate_a(state);
}

void	sort_stack(t_state *state)
{
	if (state->stack_a->size == 2)
		return (sort_two_elements_stack(state));
	else if (state->stack_a->size == MIN_NUMBERS_TO_SORT)
		return (sort_three_elements_stack(state));
	else if (state->stack_a->size == MIN_NUMBERS_TO_SORT + 1)
		return (sort_four_elements_stack(state));
	push_b(state);
	push_b(state);
	push_to_stack_b(state);
	sort_three_elements_stack(state);
	push_back_to_stack_a(state);
}

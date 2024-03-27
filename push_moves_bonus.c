/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:40:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 21:01:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	push_empty_stack(t_stack *dest, t_element *extracted)
{
	extracted->next = NULL;
	extracted->prev = NULL;
	dest->top_element = extracted;
	return (1);
}

static int	push_one_element_stack(t_stack *dest, t_element *extracted)
{
	dest->top_element->next = extracted;
	dest->top_element->prev = extracted;
	extracted->next = dest->top_element;
	extracted->prev = dest->top_element;
	dest->top_element = extracted;
	return (1);
}

static int	push(t_stack *dest, t_stack *source)
{
	t_element	*extracted;
	t_element	*first_element;
	t_element	*last_element;

	if (!source->top_element)
		return (0);
	extracted = source->top_element;
	extract_element(source);
	if (!dest->top_element)
		return (push_empty_stack(dest, extracted));
	if (!dest->top_element->next)
		return (push_one_element_stack(dest, extracted));
	first_element = dest->top_element;
	last_element = first_element->prev;
	extracted->next = first_element;
	extracted->prev = last_element;
	first_element->prev = extracted;
	last_element->next = extracted;
	dest->top_element = extracted;
	return (1);
}

void	push_a(t_state *state)
{
	if (!push(state->stack_a, state->stack_b))
		return ;
	state->stack_a->size++;
	state->stack_b->size--;
	state->stack_a->biggest = get_biggest_number(state->stack_a);
	state->stack_b->biggest = get_biggest_number(state->stack_b);
	state->stack_a->smallest = get_smallest_number(state->stack_a);
	state->stack_b->smallest = get_smallest_number(state->stack_b);
}

void	push_b(t_state *state)
{
	if (!push(state->stack_b, state->stack_a))
		return ;
	state->stack_a->size--;
	state->stack_b->size++;
	state->stack_a->biggest = get_biggest_number(state->stack_a);
	state->stack_b->biggest = get_biggest_number(state->stack_b);
	state->stack_a->smallest = get_smallest_number(state->stack_a);
	state->stack_b->smallest = get_smallest_number(state->stack_b);
}

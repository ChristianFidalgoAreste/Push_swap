/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:59:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	swap_two_elements_stack(t_stack *stack)
{
	stack->top_element = stack->top_element->next;
	return (1);
}

static int	swap(t_stack *stack)
{
	t_element	*first_element;
	t_element	*second_element;
	t_element	*third_element;
	t_element	*last_element;

	if (stack->size < 2)
		return (0);
	else if (stack->size == 2)
		return (swap_two_elements_stack(stack));
	first_element = stack->top_element;
	second_element = first_element->next;
	third_element = second_element->next;
	last_element = first_element->prev;
	first_element->prev = second_element;
	first_element->next = third_element;
	second_element->prev = last_element;
	second_element->next = first_element;
	last_element->next = second_element;
	third_element->prev = first_element;
	stack->top_element = second_element;
	return (1);
}

void	swap_a(t_state *state)
{
	swap(state->stack_a);
}

void	swap_b(t_state *state)
{
	swap(state->stack_b);
}

void	swap_both(t_state *state)
{
	swap(state->stack_a);
	swap(state->stack_b);
}

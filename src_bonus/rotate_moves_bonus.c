/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:45:49 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 21:00:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	rotate(t_stack *stack)
{
	if (stack->size <= 1)
		return (0);
	stack->top_element = stack->top_element->next;
	return (1);
}

void	rotate_a(t_state *state)
{
	rotate(state->stack_a);
}

void	rotate_b(t_state *state)
{
	rotate(state->stack_b);
}

void	rotate_both(t_state *state)
{
	rotate(state->stack_a);
	rotate(state->stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:19:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 21:02:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	reverse_rotate(t_stack *stack)
{
	if (stack->size <= 1)
		return (0);
	stack->top_element = stack->top_element->prev;
	return (1);
}

void	rev_rotate_a(t_state *state)
{
	reverse_rotate(state->stack_a);
}

void	rev_rotate_b(t_state *state)
{
	reverse_rotate(state->stack_b);
}

void	rev_rotate_both(t_state *state)
{
	reverse_rotate(state->stack_a);
	reverse_rotate(state->stack_b);
}

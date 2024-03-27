/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:53:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 19:31:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_move_cost(t_state *state)
{
	int	move_cost;

	move_cost = 0;
	move_cost += state->moves->ra + state->moves->rb + state->moves->rr;
	move_cost += state->moves->rra + state->moves->rrb + state->moves->rrr;
	return (move_cost);
}

void	calculate_double_rotations(t_state *state)
{
	while (state->moves->ra > 0 && state->moves->rb > 0)
	{
		state->moves->rr++;
		state->moves->ra--;
		state->moves->rb--;
	}
	while (state->moves->rra > 0 && state->moves->rrb > 0)
	{
		state->moves->rrr++;
		state->moves->rra--;
		state->moves->rrb--;
	}
}

void	execute_moves(t_state *state)
{
	while (state->moves->ra-- > 0)
		rotate_a(state);
	while (state->moves->rb-- > 0)
		rotate_b(state);
	while (state->moves->rr-- > 0)
		rotate_both(state);
	while (state->moves->rra-- > 0)
		rev_rotate_a(state);
	while (state->moves->rrb-- > 0)
		rev_rotate_b(state);
	while (state->moves->rrr-- > 0)
		rev_rotate_both(state);
	reset_moves(state->moves);
}

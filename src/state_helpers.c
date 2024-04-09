/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:48:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 19:31:19 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_moves(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
}

static t_moves	*init_moves(void)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
		return (NULL);
	reset_moves(moves);
	return (moves);
}

static t_stack	*create_stack(int argc, char **argv)
{
	int			i;
	t_stack		*stack;
	t_element	*element;
	t_element	*top_element;

	i = 0;
	top_element = NULL;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	while (i < argc)
	{
		element = new_stack(argv[i]);
		if (!element)
			return (NULL);
		stack_add_back(&top_element, element);
		i++;
	}
	if (argc > 1)
	{
		element->next = top_element;
		top_element->prev = element;
	}
	stack->top_element = top_element;
	return (stack);
}

void	clear_state(t_state *state)
{
	clear_stack(state->stack_a);
	clear_stack(state->stack_b);
	if (state->moves)
		free(state->moves);
}

int	init_state(t_state *state, int argc, char **argv)
{
	state->argc = argc;
	state->argv = argv;
	state->stack_a = create_stack(argc, argv);
	if (!state->stack_a)
		return (0);
	state->stack_b = create_stack(0, NULL);
	if (!state->stack_b)
		return (clear_stack(state->stack_a), 0);
	state->stack_a->size = argc;
	state->stack_a->biggest = get_biggest_number(state->stack_a);
	state->stack_a->smallest = get_smallest_number(state->stack_a);
	state->stack_b->size = 0;
	state->stack_b->biggest = 0;
	state->stack_b->smallest = 0;
	state->min_move_cost_num = 0;
	state->move_cost = argc;
	state->moves = init_moves();
	if (!state->moves)
		return (clear_state(state), 0);
	return (1);
}

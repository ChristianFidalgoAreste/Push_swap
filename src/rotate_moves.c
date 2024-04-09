/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:45:49 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/20 13:49:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *stack)
{
	if (stack->size <= 1)
		return (0);
	stack->top_element = stack->top_element->next;
	return (1);
}

void	rotate_a(t_state *state)
{
	if (!rotate(state->stack_a))
		return ;
	ft_printf("ra\n");
}

void	rotate_b(t_state *state)
{
	if (!rotate(state->stack_b))
		return ;
	ft_printf("rb\n");
}

void	rotate_both(t_state *state)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = rotate(state->stack_a);
	rotate_b = rotate(state->stack_b);
	if (rotate_a && !rotate_b)
		ft_printf("ra\n");
	else if (!rotate_a && rotate_b)
		ft_printf("rb\n");
	else if (rotate_a && rotate_b)
		ft_printf("rr\n");
}

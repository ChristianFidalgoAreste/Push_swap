/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:19:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:54:20 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *stack)
{
	if (stack->size <= 1)
		return (0);
	stack->top_element = stack->top_element->prev;
	return (1);
}

void	rev_rotate_a(t_state *state)
{
	if (!reverse_rotate(state->stack_a))
		return ;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_state *state)
{
	if (!reverse_rotate(state->stack_b))
		return ;
	ft_printf("rrb\n");
}

void	rev_rotate_both(t_state *state)
{
	int	rev_rotate_a;
	int	rev_rotate_b;

	rev_rotate_a = reverse_rotate(state->stack_a);
	rev_rotate_b = reverse_rotate(state->stack_b);
	if (rev_rotate_a && !rev_rotate_b)
		ft_printf("rra\n");
	else if (!rev_rotate_a && rev_rotate_b)
		ft_printf("rrb\n");
	else if (rev_rotate_a && rev_rotate_b)
		ft_printf("rrr\n");
}

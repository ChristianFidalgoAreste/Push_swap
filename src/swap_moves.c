/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:50:32 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!swap(state->stack_a))
		return ;
	ft_printf("sa\n");
}

void	swap_b(t_state *state)
{
	if (!swap(state->stack_b))
		return ;
	ft_printf("sb\n");
}

void	swap_both(t_state *state)
{
	int	swap_a;
	int	swap_b;

	swap_a = swap(state->stack_a);
	swap_b = swap(state->stack_b);
	if (swap_a && !swap_b)
		ft_printf("sa\n");
	else if (!swap_a && swap_b)
		ft_printf("sb\n");
	else if (swap_a && swap_b)
		ft_printf("ss\n");
}

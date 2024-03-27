/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_properties_helpers_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:45:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:50:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_smallest_number(t_stack *stack)
{
	int			i;
	int			num;
	t_element	*next_element;

	if (stack->size == 0)
		return (0);
	i = 0;
	num = stack->top_element->num;
	next_element = stack->top_element;
	while (i < stack->size - 1)
	{
		next_element = next_element->next;
		if (next_element && num > next_element->num)
			num = next_element->num;
		i++;
	}
	return (num);
}

int	get_biggest_number(t_stack *stack)
{
	int			i;
	int			num;
	t_element	*next_element;

	if (stack->size == 0)
		return (0);
	i = 0;
	num = stack->top_element->num;
	next_element = stack->top_element;
	while (i < stack->size - 1)
	{
		next_element = next_element->next;
		if (next_element && num < next_element->num)
			num = next_element->num;
		i++;
	}
	return (num);
}

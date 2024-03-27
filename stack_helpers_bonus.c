/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:43:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:19:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_element	*new_stack(char *number)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->num = ft_atoi(number);
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	stack_add_front(t_element **top, t_element *new)
{
	t_element	*last_element;

	if (!new || !top)
		return ;
	last_element = (*top)->prev;
	new->next = *top;
	new->prev = last_element;
	last_element->next = new;
	(*top)->prev = new;
	*top = new;
}

void	stack_add_back(t_element **top, t_element *new)
{
	t_element	*this_element;

	if (!top)
		return ;
	if (!*top)
	{
		*top = new;
		return ;
	}
	this_element = *top;
	while (this_element->next)
		this_element = this_element->next;
	this_element->next = new;
	new->prev = this_element;
}

void	extract_element(t_stack *stack)
{
	t_element	*second_element;
	t_element	*last_element;

	second_element = stack->top_element->next;
	last_element = stack->top_element->prev;
	if (stack->size == 2)
	{
		second_element->next = NULL;
		second_element->prev = NULL;
	}
	else if (stack->size > 2)
	{
		second_element->prev = last_element;
		last_element->next = second_element;
	}
	stack->top_element = second_element;
}

void	clear_stack(t_stack *stack)
{
	int			i;
	t_element	*next_element;

	if (!stack)
		return ;
	if (stack && !stack->top_element)
		return (free(stack));
	i = 0;
	next_element = stack->top_element;
	while (i < stack->size)
	{
		next_element = next_element->next;
		free(stack->top_element);
		stack->top_element = next_element;
		i++;
	}
	stack->top_element = NULL;
	free(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:25:25 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/03/24 20:43:05 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	execute_instruction(t_state *state, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		swap_a(state);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		swap_b(state);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		swap_both(state);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		push_a(state);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		push_b(state);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		rotate_a(state);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rotate_b(state);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rotate_both(state);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rev_rotate_a(state);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rev_rotate_b(state);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rev_rotate_both(state);
	else
		handle_error();
}

void	read_instructions(t_state *state)
{
	char	*instruction;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		execute_instruction(state, instruction);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
}

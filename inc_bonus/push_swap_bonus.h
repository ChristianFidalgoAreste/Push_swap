/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:48:55 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/04/09 20:26:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define ERROR_LENGTH 6
# define MAX_ARG_LENGTH 11
# define MIN_NUMBERS_TO_SORT 3
# include "../libft/libft.h"

// Structs
typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;

typedef struct s_element
{
	int					num;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_stack
{
	int			size;
	int			biggest;
	int			smallest;
	t_element	*top_element;
}	t_stack;

typedef struct s_state
{
	int		argc;
	char	**argv;
	int		move_cost;
	int		min_move_cost_num;
	t_moves	*moves;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_state;

// Stack helpers
t_element	*new_stack(char *number);
void		stack_add_front(t_element **top, t_element *new);
void		stack_add_back(t_element **top, t_element *new);
void		extract_element(t_stack *stack);
void		clear_stack(t_stack *stack);

// Stack properties helpers
int			get_smallest_number(t_stack *stack);
int			get_biggest_number(t_stack *stack);

// State helpers
void		reset_moves(t_moves *moves);
void		clear_state(t_state *state);
int			init_state(t_state *state, int argc, char **argv);

// Arguments helpers
int			check_args_validity(char **argv);

// Swap movements
void		swap_a(t_state *state);
void		swap_b(t_state *state);
void		swap_both(t_state *state);

// Push movements
void		push_a(t_state *state);
void		push_b(t_state *state);

// Rotate movements
void		rotate_a(t_state *state);
void		rotate_b(t_state *state);
void		rotate_both(t_state *state);

// Reverse rotate movements
void		rev_rotate_a(t_state *state);
void		rev_rotate_b(t_state *state);
void		rev_rotate_both(t_state *state);

// Read instructions
void		read_instructions(t_state *state);

// Error handlers
void		handle_error(void);

#endif

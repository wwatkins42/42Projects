/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:36:15 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 16:08:36 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define ABS(x) (x < 0 ? -x : x)
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define COLOR_RED "\e[31m"
# define COLOR_GREEN "\e[32m"
# define COLOR_ORANGE "\e[33m"
# define COLOR_BLUE "\e[34m"
# define COLOR_MAGENTA "\e[35m"
# define COLOR_CYAN "\e[36m"
# define COLOR_GREY "\e[90m"
# define COLOR_YELLOW "\e[93m"
# define COLOR_END "\e[0m"

enum { ONE, BOTH };
enum { INC, DEC };

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_move
{
	char			*name;
	struct s_move	*next;
}				t_move;

typedef struct	s_arg
{
	short	verbose;
	short	color;
}				t_arg;

typedef struct	s_env
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_end_a;
	t_stack	*stack_end_b;
	t_move	*move;
	t_move	*move_end;
	t_arg	arg;
	int		count_min;
	int		count;
	int		min;
	int		max;
	int		m;
}				t_env;

/*
**	main.c
*/

void			check_args(t_env *e, int argc, char **argv);
void			create_stacks(t_env *e, int argc, char **argv);
void			error(int err);

/*
**	resolve.c
*/

int				sort(t_env *e);
int				get_minmax(t_env *e);
int				check_sorted(t_stack *stack, int mode);

/*
**	move_swap.c
*/

int				move_swap_a(t_env *e, int move);
int				move_swap_b(t_env *e, int move);
void			move_swap_both(t_env *e);

/*
**	move_push.c
*/

void			move_push_a(t_env *e);
void			move_push_b(t_env *e);

/*
**	move_rotate.c
*/

int				move_rotate_a(t_env *e, int move);
int				move_rotate_b(t_env *e, int move);
void			move_rotate_both(t_env *e);

/*
**	move_reverse_rotate.c
*/

int				move_rev_rotate_a(t_env *e, int move);
int				move_rev_rotate_b(t_env *e, int move);
void			move_rev_rotate_both(t_env *e);

/*
**	utils.c
*/

void			add_move(t_env *e, char *move);
void			disp_moves(t_env *e);
void			disp_stack(t_env *e, t_stack *stack, char c);
void			set_color(char *name);

#endif

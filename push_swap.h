/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:12:41 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:16:31 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

# define CYN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

typedef struct	s_stacks
{
	int			*stack_a;
	int			*stack_b;
	int			count_a;
	int			count_b;
	int			min;
	int			max;
	int			flag_v;
	int			flag_c;
}				t_stacks;

typedef struct	s_com
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
	int			count;
}				t_com;

void			ft_do_sa(t_stacks *stacks);
void			ft_do_sb(t_stacks *stacks);
void			ft_do_rra(t_stacks *stacks);
void			ft_do_ra(t_stacks *stacks);
void			ft_do_rrb(t_stacks *stacks);
void			ft_do_rb(t_stacks *stacks);
void			ft_do_pb(t_stacks *stacks);
void			ft_do_pa(t_stacks *stacks);
void			ft_pars_flags(char ***av, t_stacks *stacks);
void			ft_creat_stacks(t_stacks *stacks, int ac, char **av);
void			ft_do_com(t_com com, t_stacks *stacks);
void			ft_get_com(t_stacks stacks, t_com *com, int i);
void			ft_solver_algo(t_stacks stacks);
int				ft_check_solve(t_stacks stacks);
void			ft_print_stacks(t_stacks stacks);
void			ft_solver_for_three(t_stacks *stacks);
void			ft_separate(t_stacks *stacks);
void			ft_free_arr_push(char **arr);
void			ft_print_error(t_stacks *stacks);
void			free_all(t_stacks *stacks);

#endif

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

typedef struct      s_stacks
{
	int             *stack_a;
	int             *stack_b;
	int             count_a;
	int             count_b;
}                   t_stacks;

void	ft_do_sa(t_stacks *stacks);
void	ft_do_sb(t_stacks *stacks);
void	ft_do_rra(t_stacks *stacks);
void	ft_do_ra(t_stacks *stacks);
void	ft_do_rrb(t_stacks *stacks);
void	ft_do_rb(t_stacks *stacks);
void	ft_do_pb(t_stacks *stacks);
void	ft_do_pa(t_stacks *stacks);

#endif

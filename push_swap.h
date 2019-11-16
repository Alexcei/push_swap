#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

# define CYN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"
# define CLR "\e[1;1H\e[?25l"

# define KO ft_putendl_fd("KO", 2);

typedef struct      s_stacks
{
	int             *stack_a;
	int             *stack_b;
	int             count_a;
	int             count_b;
	int 			flag_v;
	int 			flag_c;
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
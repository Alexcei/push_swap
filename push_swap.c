/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:09:58 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:12:34 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		solver_for_three_next(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a > c && b > c)
	{
		stacks->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
		ft_do_rra(stacks);
	}
	else if (a > b && a < c && b < c)
	{
		stacks->flag_c ? ft_printf(CYN"sa\n"RESET) : ft_printf("sa\n");
		ft_do_sa(stacks);
	}
	else if (a < b && a < c && b > c)
	{
		stacks->flag_c ? ft_printf(CYN"rra\nsa\n"RESET)
			: ft_printf("rra\nsa\n");
		ft_do_rra(stacks);
		ft_do_sa(stacks);
	}
}

void			ft_solver_for_three(t_stacks *stacks)
{
	int			a;
	int			b;
	int			c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a > b && a > c && b > c)
	{
		stacks->flag_c ? ft_printf(CYN"sa\nrra\n"RESET)
			: ft_printf("sa\nrra\n");
		ft_do_sa(stacks);
		ft_do_rra(stacks);
	}
	else if (a > b && a > c && b < c)
	{
		stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		ft_do_ra(stacks);
	}
	else
		solver_for_three_next(stacks, a, b, c);
}

void			solver(t_stacks stacks)
{
	if (stacks.count_a == 3 || stacks.count_a == 1)
		ft_solver_for_three(&stacks);
	else if (stacks.count_a == 2 && stacks.stack_a[0] > stacks.stack_a[1])
		stacks.flag_c ? ft_printf(CYN"sa\n"RESET) : ft_printf("sa\n");
	else if (stacks.count_a > 3)
		ft_solver_algo(stacks);
}

int				main(int ac, char **av)
{
	t_stacks	stacks;

	av++;
	ac--;
	ft_bzero(&stacks, sizeof(t_stacks));
	ft_pars_flags(&av, &stacks);
	if (!ac)
		return (0);
	ft_creat_stacks(&stacks, ac, av);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
	solver(stacks);
	free_all(&stacks);
	return (0);
}

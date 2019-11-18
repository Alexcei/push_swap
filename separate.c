/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:16:45 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:23:13 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		do_pb_res(t_stacks *stacks)
{
	ft_do_pb(stacks);
	stacks->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
}

static void		average_division(t_stacks *stacks)
{
	long		m;
	int			limit;
	int			i;

	m = (stacks->max + stacks->min) / 2;
	limit = stacks->count_a;
	i = 0;
	while (limit > 50 && i++ < limit)
	{
		if (stacks->stack_a[0] == stacks->min
				|| stacks->stack_a[0] == stacks->max || stacks->stack_a[0] < m)
		{
			ft_do_ra(stacks);
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		}
		else
			do_pb_res(stacks);
	}
}

void			ft_separate(t_stacks *stacks)
{
	int			i;

	i = -1;
	stacks->min = stacks->stack_a[0];
	stacks->max = stacks->stack_a[0];
	while (++i < stacks->count_a)
	{
		if (stacks->stack_a[i] < stacks->min)
			stacks->min = stacks->stack_a[i];
		if (stacks->stack_a[i] > stacks->max)
			stacks->max = stacks->stack_a[i];
	}
	average_division(stacks);
	while (stacks->count_a > 3)
	{
		if (stacks->stack_a[0] == stacks->min
				|| stacks->stack_a[0] == stacks->max)
		{
			ft_do_ra(stacks);
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		}
		else
			do_pb_res(stacks);
	}
}

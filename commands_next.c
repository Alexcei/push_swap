/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:55:09 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 21:58:37 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_do_rrb(t_stacks *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->stack_b[stacks->count_b - 1];
	i = stacks->count_b + 1;
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
}

void		ft_do_rb(t_stacks *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->stack_b[0];
	i = 0;
	while (++i <= stacks->count_b)
		stacks->stack_b[i - 1] = stacks->stack_b[i];
	stacks->stack_b[stacks->count_b - 1] = tmp;
}

void		ft_do_rra(t_stacks *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->stack_a[stacks->count_a - 1];
	i = stacks->count_a + 1;
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
}

void		ft_do_ra(t_stacks *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->stack_a[0];
	i = 0;
	while (++i <= stacks->count_a)
		stacks->stack_a[i - 1] = stacks->stack_a[i];
	stacks->stack_a[stacks->count_a - 1] = tmp;
}

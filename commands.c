/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:50:24 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 21:54:59 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *a, int *b)
{
	int			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_do_sa(t_stacks *stacks)
{
	swap(&stacks->stack_a[0], &stacks->stack_a[1]);
}

void			ft_do_sb(t_stacks *stacks)
{
	swap(&stacks->stack_b[0], &stacks->stack_b[1]);
}

void			ft_do_pb(t_stacks *stacks)
{
	int			i;

	if (!stacks->count_a)
		return ;
	i = stacks->count_b + 1;
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	swap(&stacks->stack_a[0], &stacks->stack_b[0]);
	stacks->count_b++;
	i = 0;
	while (++i <= stacks->count_a)
		stacks->stack_a[i - 1] = stacks->stack_a[i];
	stacks->count_a--;
}

void			ft_do_pa(t_stacks *stacks)
{
	int			i;

	if (!stacks->count_b)
		return ;
	i = stacks->count_a + 1;
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	swap(&stacks->stack_b[0], &stacks->stack_a[0]);
	stacks->count_a++;
	i = 0;
	while (++i <= stacks->count_b)
		stacks->stack_b[i - 1] = stacks->stack_b[i];
	stacks->count_b--;
}

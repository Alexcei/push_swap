/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:23:19 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:24:46 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_min(int *arr, int count)
{
	int			min;
	int			res;
	int			i;

	i = 0;
	min = arr[0];
	res = 0;
	while (i < count)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			res = i;
		}
		i++;
	}
	return (res);
}

static void		drum_sort(t_stacks *stacks)
{
	t_com		com;
	int			arr[stacks->count_b];
	int			i;
	int			min;

	i = 0;
	while (i < stacks->count_b)
	{
		ft_bzero(&com, sizeof(t_com));
		ft_get_com(*stacks, &com, i);
		arr[i] = com.count;
		i++;
	}
	min = find_min(arr, stacks->count_b);
	ft_bzero(&com, sizeof(t_com));
	ft_get_com(*stacks, &com, min);
	ft_do_com(com, stacks);
}

static void		shift(t_stacks *stacks)
{
	int			i;
	int			back;

	i = 0;
	while (stacks->stack_a[i] != stacks->min)
		i++;
	back = stacks->count_a - i;
	if (i > back)
	{
		while (back--)
		{
			ft_do_rra(stacks);
			stacks->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
		}
	}
	else
	{
		while (i--)
		{
			ft_do_ra(stacks);
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		}
	}
}

void			ft_solver_algo(t_stacks stacks)
{
	if (ft_check_solve(stacks))
		return ;
	ft_separate(&stacks);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
	ft_solver_for_three(&stacks);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
	while (stacks.count_b)
	{
		drum_sort(&stacks);
		if (stacks.flag_v)
			ft_print_stacks(stacks);
	}
	if (!ft_check_solve(stacks))
		shift(&stacks);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
}

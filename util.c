/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:01:00 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:02:54 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_pars_flags(char ***av, t_stacks *stacks)
{
	if (ft_strequ(**av, "-v"))
	{
		stacks->flag_v = 1;
		(*av)++;
		ft_pars_flags(av, stacks);
	}
	if (ft_strequ(**av, "-c"))
	{
		stacks->flag_c = 1;
		(*av)++;
		ft_pars_flags(av, stacks);
	}
}

int			ft_check_solve(t_stacks stacks)
{
	int		previos;
	int		i;

	i = 0;
	if (stacks.count_b)
		return (0);
	while (stacks.count_a--)
	{
		if (i)
		{
			if (stacks.stack_a[i] < previos)
				return (0);
		}
		previos = stacks.stack_a[i];
		i++;
	}
	return (1);
}

void		ft_print_stacks(t_stacks stacks)
{
	stacks.flag_c ? ft_printf(YEL"STACK A %d elem - "RESET, stacks.count_a) :
		ft_printf("STACK A %d elem - ", stacks.count_a);
	if (!stacks.count_a)
		stacks.flag_c ? ft_printf(YEL"empty"RESET) : ft_printf("empty");
	else
	{
		while (stacks.count_a--)
			stacks.flag_c ? ft_printf(YEL"%d "RESET, *stacks.stack_a++) :
				ft_printf("%d ", *stacks.stack_a++);
	}
	ft_printf("\n");
	stacks.flag_c ? ft_printf(BLU"STACK B %d elem - "RESET, stacks.count_b) :
		ft_printf("STACK B %d elem - ", stacks.count_b);
	if (!stacks.count_b)
		stacks.flag_c ? ft_printf(BLU"empty"RESET) :
			ft_printf("empty");
	else
	{
		while (stacks.count_b--)
			stacks.flag_c ? ft_printf(BLU"%d "RESET, *stacks.stack_b++) :
				ft_printf("%d ", *stacks.stack_b++);
	}
	ft_printf("\n");
}

void		free_all(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
}

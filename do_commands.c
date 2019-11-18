/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:25:36 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:26:02 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		do_com_next(t_com com, t_stacks *stacks)
{
	while (com.rr--)
	{
		ft_do_ra(stacks);
		ft_do_rb(stacks);
		stacks->flag_c ? ft_printf(CYN"rr\n"RESET) : ft_printf("rr\n");
	}
	while (com.rrr--)
	{
		ft_do_rra(stacks);
		ft_do_rrb(stacks);
		stacks->flag_c ? ft_printf(CYN"rrr\n"RESET) : ft_printf("rrr\n");
	}
	ft_do_pa(stacks);
	stacks->flag_c ? ft_printf(CYN"pa\n"RESET) : ft_printf("pa\n");
}

void			ft_do_com(t_com com, t_stacks *stacks)
{
	while (com.ra--)
	{
		ft_do_ra(stacks);
		stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
	}
	while (com.rra--)
	{
		ft_do_rra(stacks);
		stacks->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
	}
	while (com.rb--)
	{
		ft_do_rb(stacks);
		stacks->flag_c ? ft_printf(CYN"rb\n"RESET) : ft_printf("rb\n");
	}
	while (com.rrb--)
	{
		ft_do_rrb(stacks);
		stacks->flag_c ? ft_printf(CYN"rrb\n"RESET) : ft_printf("rrb\n");
	}
	do_com_next(com, stacks);
}

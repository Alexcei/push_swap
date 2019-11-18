/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:47:12 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 21:50:08 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		apply_command_next(t_stacks *stacks, char *line)
{
	if (ft_strequ(line, "ss"))
	{
		ft_do_sa(stacks);
		ft_do_sb(stacks);
	}
	else if (ft_strequ(line, "rr"))
	{
		ft_do_ra(stacks);
		ft_do_rb(stacks);
	}
	else if (ft_strequ(line, "rrr"))
	{
		ft_do_rra(stacks);
		ft_do_rrb(stacks);
	}
	else
		ft_print_error(stacks);
}

static void		apply_command(t_stacks *stacks, char *line)
{
	if (ft_strequ(line, "sa"))
		ft_do_sa(stacks);
	else if (ft_strequ(line, "ra"))
		ft_do_ra(stacks);
	else if (ft_strequ(line, "rra"))
		ft_do_rra(stacks);
	else if (ft_strequ(line, "pb"))
		ft_do_pb(stacks);
	else if (ft_strequ(line, "pa"))
		ft_do_pa(stacks);
	else if (ft_strequ(line, "sb"))
		ft_do_sb(stacks);
	else if (ft_strequ(line, "rb"))
		ft_do_rb(stacks);
	else if (ft_strequ(line, "rrb"))
		ft_do_rrb(stacks);
	else
		apply_command_next(stacks, line);
}

static int		next_command(t_stacks *stacks)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (stacks->flag_v)
			stacks->flag_c ? ft_printf(MAG"Last operation %s\n"RESET, line)
			: ft_printf("Last operation %s\n", line);
		apply_command(stacks, line);
		free(line);
		if (stacks->flag_v)
			ft_print_stacks(*stacks);
	}
	if (ft_check_solve(*stacks))
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_stacks	stacks;

	av++;
	ft_bzero(&stacks, sizeof(t_stacks));
	ft_pars_flags(&av, &stacks);
	if (ac == 1)
		return (0);
	ft_creat_stacks(&stacks, ac - 1, av);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
	if (next_command(&stacks))
		stacks.flag_c ? ft_printf(GRN"OK\n"RESET) : ft_printf("OK\n");
	else
		stacks.flag_c ? ft_printf(RED"KO\n"RESET) : ft_printf("KO\n");
	free_all(&stacks);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:26:10 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:27:21 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "push_swap.h"

static void		get_ra_rra(t_stacks stacks, t_com *com, int i)
{
	int			up;
	int			b;

	up = 0;
	b = stacks.stack_b[i];
	while (42)
	{
		if (!up && stacks.stack_a[0] != stacks.min
				&& b > stacks.stack_a[stacks.count_a - 1]
				&& b < stacks.stack_a[0])
			break ;
		else if (up && stacks.stack_a[up] != stacks.min
				&& b > stacks.stack_a[up - 1] && b < stacks.stack_a[up])
			break ;
		up++;
	}
	com->ra = up;
	com->rra = stacks.count_a - up;
}

static void		get_rb_rrb(t_stacks stacks, t_com *com, int i)
{
	com->rb = i;
	com->rrb = stacks.count_b - i;
}

static void		get_rr_rrr(t_com *com)
{
	com->rr = MIN(com->ra, com->rb);
	com->ra -= com->rr;
	com->rb -= com->rr;
	com->rrr = MIN(com->rra, com->rrb);
	com->rra -= com->rrr;
	com->rrb -= com->rrr;
}

static void		optimal_com(t_com *com)
{
	if (com->ra + com->rb + com->rr < com->rra + com->rrb + com->rrr)
	{
		com->count = com->ra + com->rb + com->rr;
		com->rrr = 0;
		com->rra = 0;
		com->rrb = 0;
	}
	else
	{
		com->count = com->rra + com->rrb + com->rrr;
		com->rr = 0;
		com->ra = 0;
		com->rb = 0;
	}
}

void			ft_get_com(t_stacks stacks, t_com *com, int i)
{
	get_ra_rra(stacks, com, i);
	get_rb_rrb(stacks, com, i);
	get_rr_rrr(com);
	optimal_com(com);
}

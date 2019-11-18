#include "push_swap.h"

int 	next_is_max_or_min(t_stacks *stacks)
{
	int 	i;

	i = 0;
	while (i < stacks->count_a)
	{
		if (stacks->stack_a[i] == stacks->max)
			return (1);
		else if (stacks->stack_a[i] == stacks->min)
			return (0);
		i++;
	}
	return (0);
}

void	separate(t_stacks *stacks)
{
	int 	i;
	int 	value;
	int 	count_a;

	i = 0;
	count_a = 2;
	stacks->min = stacks->stack_a[0];
	stacks->max = stacks->stack_a[0];
	while (i < stacks->count_a)
	{
		if (stacks->stack_a[i] < stacks->min)
			stacks->min = stacks->stack_a[i];
		if (stacks->stack_a[i] > stacks->max)
			stacks->max = stacks->stack_a[i];
		i++;
	}
	value = stacks->min;
	while (stacks->count_a > count_a)
	{
		if (stacks->stack_a[0] == stacks->min || stacks->stack_a[0] == stacks->max)
		{
			if (stacks->stack_a[0] == stacks->max)
				value = stacks->max;
			ft_do_ra(stacks);
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		}
		else
		{
			if (next_is_max_or_min(stacks) && stacks->stack_a[0] > value)
			{
				count_a++;
				value = stacks->stack_a[0];
				ft_do_ra(stacks);
				stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
				continue ;
			}
			if (stacks->stack_a[1] != stacks->min && stacks->stack_a[1] != stacks->max && stacks->stack_a[0] < stacks->stack_a[1])
			{
				if (stacks->count_b > 1 && stacks->stack_b[0] > stacks->stack_a[1])
				{
					ft_do_sa(stacks);
					ft_do_sb(stacks);
					stacks->flag_c ? ft_printf(CYN"ss\n"RESET) : ft_printf("ss\n");
				}
			}
			ft_do_pb(stacks);
			stacks->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
		}
		//ft_print_stacks(*stacks);
	}
}
/*
void 	optimal(t_stacks *stacks)
{
	int 	b;
	int 	next;
	int 	up;
	//int 	back;
	int 	arr[stacks->count_b];

	next = 0;
	while (next < stacks->count_b)
	{
		up = 0;
		b = stacks->stack_b[next];
		while (42)
		{
			if (!up && stacks->stack_a[0] != stacks->min && b > stacks->stack_a[stacks->count_a - 1] &&
				b < stacks->stack_a[0])
				break;
			else if (up && stacks->stack_a[up] != stacks->min && b > stacks->stack_a[up - 1] && b < stacks->stack_a[up])
				break;
			up++;
		}
		arr[next] = up;
		next++;
	}
	stacks->next = next;
	stacks->up = up;
	next = 0;
	while (next < stacks->count_b)
	{
		if (arr[next] + next < stacks->up)
		{
			stacks->next = next;
			stacks->up = arr[next];
		}
		next++;
	}
	ft_printf("%d %d %d\n", stacks->next, stacks->up, arr[next]);
	//stacks->back = stacks->count_a - up;
}
 	optimal(stacks);
	next = stacks->next;
	up = stacks->up;
 	back = stacks->back;
*/
/*
void	drum_sort(t_stacks *stacks)
{
	//int 	next;
	int 	b;
	int		up;
	int 	back;




	up = 0;
	b = stacks->stack_b[0];
	while (42)
	{
		if (!up && stacks->stack_a[0] != stacks->min && b > stacks->stack_a[stacks->count_a - 1] && b < stacks->stack_a[0])
			break ;
		else if (up && stacks->stack_a[up] != stacks->min && b > stacks->stack_a[up - 1] && b < stacks->stack_a[up])
			break ;
		up++;
	}
	back = stacks->count_a - up;

	if (up > 12 && back > 12)
	{
		ft_do_ra(stacks);
		ft_do_rb(stacks);
		stacks->flag_c ? ft_printf(CYN"rr\n"RESET) : ft_printf("rr\n");
		return ;
	}


	//while (next--)
	//{
	//	ft_do_rb(stacks);
	//	stacks->flag_c ? ft_printf(CYN"rb\n"RESET) : ft_printf("rb\n");
	//}
	if (up > back)
	{
		while (back--)
		{
			ft_do_rra(stacks);
			stacks->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
		}
	}
	else
	{
		while (up--)
		{
			ft_do_ra(stacks);
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		}
	}
	ft_do_pa(stacks);
	stacks->flag_c ? ft_printf(CYN"pa\n"RESET) : ft_printf("pa\n");
}
*/

int 	find_min(int *arr, int count)
{
	int		min;
	int 	res;
	int		i;

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

void	do_com(t_com com, t_stacks *stacks)
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

void	get_ra_rra(t_stacks stacks, t_com *com, int i)
{
	int 	up;
	int 	b;

	up = 0;
	b = stacks.stack_b[i];
	while (42)
	{
		if (!up && stacks.stack_a[0] != stacks.min && b > stacks.stack_a[stacks.count_a - 1] && b < stacks.stack_a[0])
			break ;
		else if (up && stacks.stack_a[up] != stacks.min && b > stacks.stack_a[up - 1] && b < stacks.stack_a[up])
			break ;
		up++;
	}
	com->ra = up;
	com->rra = stacks.count_a - up;
}

void	get_rb_rrb(t_stacks stacks, t_com *com, int i)
{
	com->rb = i;
	com->rrb = stacks.count_b - i;
}

void	get_rr_rrr(t_com *com)
{
	com->rr = MIN(com->ra, com->rb);
	com->ra -= com->rr;
	com->rb -= com->rr;
	com->rrr = MIN(com->rra, com->rrb);
	com->rra -= com->rrr;
	com->rrb -= com->rrr;
}

void	optimal_com(t_com *com)
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

void	get_com(t_stacks stacks, t_com *com, int i)
{
	get_ra_rra(stacks, com, i);
	get_rb_rrb(stacks, com, i);
	get_rr_rrr(com);
	optimal_com(com);
}

void	drum_sort(t_stacks *stacks)
{
	t_com	com;
	int 	arr[stacks->count_b];
	int 	i;
	int 	min;

	i = 0;
	while (i < stacks->count_b)
	{
		ft_bzero(&com, sizeof(t_com));
		get_com(*stacks, &com, i);
		arr[i] = com.count;
		i++;
	}
	min = find_min(arr, stacks->count_b);
	ft_bzero(&com, sizeof(t_com));
	get_com(*stacks, &com, min);
	do_com(com, stacks);
}

void	shift(t_stacks *stacks)
{
	int 	i;
	int 	back;

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

void	solver_algo(t_stacks stacks)
{
	if (check_solve(stacks))
		return ;
	separate(&stacks);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
	//solver_for_3(&stacks);
	//if (stacks.flag_v)
	//	ft_print_stacks(stacks);
	while (stacks.count_b)
	{
		drum_sort(&stacks);
		if (stacks.flag_v)
			ft_print_stacks(stacks);
	}
	if (!check_solve(stacks))
		shift(&stacks);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
}

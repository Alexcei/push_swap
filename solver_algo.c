#include "push_swap.h"

void	separate(t_stacks *stacks)
{
	int 	i;

	i = 0;
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
	while (stacks->count_a > 3)
	{
		if (stacks->stack_a[0] == stacks->min || stacks->stack_a[0] == stacks->max)
		{
			ft_do_ra(stacks);
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		}
		else
		{
			ft_do_pb(stacks);
			stacks->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
		}
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

/*
	while (next--)
	{
		ft_do_rb(stacks);
		stacks->flag_c ? ft_printf(CYN"rb\n"RESET) : ft_printf("rb\n");
	}*/
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
	solver_for_3(&stacks);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
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

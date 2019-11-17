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

void	drum_sort(t_stacks *stacks)
{
	int		i;
	int 	b;
	int 	back;

	i = 0;
	b = stacks->stack_b[0];
	while (42)
	{
		if (!i && stacks->stack_a[0] != stacks->min && b > stacks->stack_a[stacks->count_a - 1] && b < stacks->stack_a[0])
			break ;
		else if (i && stacks->stack_a[i] != stacks->min && b > stacks->stack_a[i - 1] && b < stacks->stack_a[i])
			break ;
		i++;
	}
	back = stacks->count_a - i;
	//ft_printf("%d %d\n", i, back);
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

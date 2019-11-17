#include "push_swap.h"

int 	check_double(t_stacks stack)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < stack.count_a)
	{
		j = i + 1;
		while (j < stack.count_a)
		{
			if (stack.stack_a[i] == stack.stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_atoi_swap(const char *str, t_stacks *stacks)
{
	size_t		i;
	int			sing;
	long long	res;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sing = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - '0';
		if (res > (res * 10) || (res > 2147483647 && sing == 1) || (res > 2147483648 && sing == -1))
		{
			stacks->flag_c ? ft_printf(RED"Error\n"RESET) : ft_printf("Error\n");
			exit(1);
		}
	}
	if (str[i] || (i && (str[i - 1] == '-' || str[i - 1] == '+')))
	{
		stacks->flag_c ? ft_printf(RED"Error\n"RESET) : ft_printf("Error\n");
		exit(1);
	}
	return (res * sing);
}

int     *creat_stack_a(int *ac, char **av, t_stacks *stacks)
{
	int     *stack_a;
	char 	**arr;
	int 	n;
	int     i;
	int 	j;

	i = 0;
	n = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j++])
			n++;
		i++;
	}
	*ac = n;
	stack_a = (int*)ft_memalloc(sizeof(int*) * n);
	i = 0;
	n = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j])
			stack_a[n++] = ft_atoi_swap(arr[j++], stacks);
		i++;
	}
	return (stack_a);
}

void    creat_stacks(t_stacks *stacks, int ac, char **av)
{
	stacks->stack_a = creat_stack_a(&ac, av, stacks);
	stacks->stack_b = (int*)ft_memalloc(sizeof(int*) * ac);
	stacks->count_a = ac;
	if (check_double(*stacks))
	{
		stacks->flag_c ? ft_printf(RED"Error\n"RESET) :
		ft_printf("Error\n");
		exit(1);
	}
}

void	ft_print_stacks(t_stacks stacks)
{
	stacks.flag_c ? ft_printf(YEL"STACK A %d elem - "RESET, stacks.count_a) :
	ft_printf("STACK A %d elem - ", stacks.count_a);
	if (!stacks.count_a)
		stacks.flag_c ? ft_printf(YEL"empty"RESET) :ft_printf("empty");
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

int 	check_solve(t_stacks stacks)
{
	int 	i;
	int 	previos;

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

void		apply_command(t_stacks *stacks, char *line)
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
	else if (ft_strequ(line, "ss"))
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
	{
		stacks->flag_c ? ft_printf(RED"Error\n"RESET) : ft_printf("Error\n");
		exit(1);
	}
}

int		next_command(t_stacks *stacks)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (stacks->flag_v)
			stacks->flag_c ? ft_printf(MAG"Last operation %s\n"RESET, line)
						   : ft_printf("Last operation %s\n", line);;
		apply_command(stacks, line);
		if (stacks->flag_v)
			ft_print_stacks(*stacks);
	}
	if (check_solve(*stacks))
		return (1);
	return (0);
}

void	pars_flag(char ***av, t_stacks *stacks)
{

	if (ft_strequ(**av, "-v"))
	{
		stacks->flag_v = 1;
		(*av)++;
		pars_flag(av, stacks);
	}
	if (ft_strequ(**av, "-c"))
	{
		stacks->flag_c = 1;
		(*av)++;
		pars_flag(av, stacks);
	}
}

int     main(int ac, char **av)
{
	t_stacks	stacks;

	av++;
	ft_bzero(&stacks, sizeof(t_stacks));
	pars_flag(&av, &stacks);
	if (ac == 1)
		return (0);
	creat_stacks(&stacks, ac - 1, av);
	if (stacks.flag_v)
		ft_print_stacks(stacks);
	if (next_command(&stacks))
		stacks.flag_c ? ft_printf(GRN"OK\n"RESET) : ft_printf("OK\n");
	else
		stacks.flag_c ? ft_printf(RED"KO\n"RESET) : ft_printf("KO\n");
	return 0;
}
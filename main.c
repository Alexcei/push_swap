#include "ft_printf/ft_printf.h"

typedef struct      s_stacks
{
    int             *stack_a;
    int             *stack_b;
    int             count_a;
    int             count_b;
}                   t_stacks;

int     *creat_stack_a(int ac, char **av)
{
    int     *stack_a;
    int     i;

    i = 1;
    stack_a = (int*)ft_memalloc(sizeof(int*) * ac);
    while (av[i])
    {
        stack_a[i - 1] = ft_atoi(av[i]);
        i++;
    }
    return (stack_a);
}

void    creat_stacks(t_stacks *stacks, int ac, char **av)
{
    stacks->stack_a = creat_stack_a(ac, av);
    stacks->stack_b = (int*)ft_memalloc(sizeof(int*) * ac);
    stacks->count_a = ac;
}

void	ft_print_stacks(t_stacks stacks)
{
	ft_printf("STACK A %d elem - ", stacks.count_a);
	if (!stacks.count_a)
		ft_printf("empty");
	else
	{
		while (stacks.count_a--)
			ft_printf("%d ", *stacks.stack_a++);
	}
	ft_printf("\n");

	ft_printf("STACK B %d elem - ", stacks.count_b);
	if (!stacks.count_b)
		ft_printf("empty");
	else
	{
		while (stacks.count_b--)
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

void	swap(int *a, int *b)
{
	int 	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_do_sa(t_stacks *stacks)
{
	swap(&stacks->stack_a[0], &stacks->stack_a[1]);
}

void	ft_do_sb(t_stacks *stacks)
{
	swap(&stacks->stack_b[0], &stacks->stack_b[1]);
}

void	ft_do_rra(t_stacks *stacks)
{
	int		tmp;
	int 	i;

	tmp = stacks->stack_a[stacks->count_a - 1];
	i = stacks->count_a + 1;
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
}

void	ft_do_ra(t_stacks *stacks)
{
	int		tmp;
	int 	i;

	tmp = stacks->stack_a[0];
	i = 0;
	while (++i <= stacks->count_a)
		stacks->stack_a[i - 1] = stacks->stack_a[i];
	stacks->stack_a[stacks->count_a - 1] = tmp;
}

void	ft_do_rrb(t_stacks *stacks)
{
	int		tmp;
	int 	i;

	tmp = stacks->stack_b[stacks->count_b - 1];
	i = stacks->count_b + 1;
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
}

void	ft_do_rb(t_stacks *stacks)
{
	int		tmp;
	int 	i;

	tmp = stacks->stack_b[0];
	i = 0;
	while (++i <= stacks->count_b)
		stacks->stack_b[i - 1] = stacks->stack_b[i];
	stacks->stack_b[stacks->count_b - 1] = tmp;
}

void	ft_do_pb(t_stacks *stacks)
{
	int 	i;

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

void	ft_do_pa(t_stacks *stacks)
{
	int 	i;

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

void	apply_command(t_stacks *stacks, char *line)
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
}

int		next_command(t_stacks *stacks)
{
	char *line;

	if (check_solve(*stacks))
		return (1);
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("<%s>\n", line);
		apply_command(stacks, line);
		ft_print_stacks(*stacks);
	}
	if (check_solve(*stacks))
		return (1);
	return (0);
}

int     main(int ac, char **av)
{
    t_stacks     stacks;

    if (ac == 1)
        return (0);
    ft_bzero(&stacks, sizeof(t_stacks));
    creat_stacks(&stacks, ac - 1, av);

    ft_print_stacks(stacks);

	if (next_command(&stacks))
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
    return 0;
}
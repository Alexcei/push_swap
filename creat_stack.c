/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:58:44 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:00:40 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_double(t_stacks stack)
{
	int		i;
	int		j;

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

static int	ft_atoi_swap(const char *str, t_stacks *stacks)
{
	size_t	i;
	int		sing;
	long	res;

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
		if (res > (res * 10) || (res > 2147483647 && sing == 1)
				|| (res > 2147483648 && sing == -1))
			ft_print_error(stacks);
	}
	if (str[i] || (i && (str[i - 1] == '-' || str[i - 1] == '+')))
		ft_print_error(stacks);
	return (res * sing);
}

static int	split_av(char **av)
{
	char	**arr;
	int		n;
	int		i;
	int		j;

	i = 0;
	n = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j++])
			n++;
		i++;
		ft_free_arr_push(arr);
	}
	return (n);
}

static int	*creat_stack_a(int *ac, char **av, t_stacks *stacks)
{
	int		*stack_a;
	char	**arr;
	int		n;
	int		i;
	int		j;

	n = split_av(av);
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
		ft_free_arr_push(arr);
	}
	return (stack_a);
}

void		ft_creat_stacks(t_stacks *stacks, int ac, char **av)
{
	stacks->stack_a = creat_stack_a(&ac, av, stacks);
	stacks->stack_b = (int*)ft_memalloc(sizeof(int*) * ac);
	stacks->count_a = ac;
	if (check_double(*stacks))
		ft_print_error(stacks);
}

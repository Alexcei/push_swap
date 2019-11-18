/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_or_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:24:54 by bpole             #+#    #+#             */
/*   Updated: 2019/11/18 22:25:22 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_arr_push(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
}

void		ft_print_error(t_stacks *stacks)
{
	stacks->flag_c ? ft_printf(RED"Error\n"RESET) : ft_printf("Error\n");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:41:40 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/15 17:43:03 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_list *list, int num)
{
	t_node	*tmp;

	tmp = list->front;
	while (tmp)
	{
		if (tmp->data == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_op(char *str, int *neg)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*neg = -1;
		if (!ft_isdigit(*(str + 1)))
			handle_error();
		return (1);
	}
	return (0);
}

int	find_max(t_list *stack_a)
{
	t_node	*tmp;
	long	max;
	long	num;
	int		i;

	i = 0;
	max = -1;
	tmp = stack_a->front;
	while (tmp)
	{
		num = tmp->idx;
		if (num > max)
			max = num;
		tmp = tmp->next;
	}
	while (max > 0)
	{
		max = max / 2;
		i++;
	}
	return (i);
}

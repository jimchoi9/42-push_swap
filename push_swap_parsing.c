/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:26:55 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/19 17:18:37 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str, t_list *list)
{
	long	num;
	int		neg;

	while (*str)
	{
		while (*str == ' ')
			str++;
		neg = 1;
		if (is_op(str, &neg))
			str++;
		num = 0;
		while (ft_isdigit(*str))
		{
			num = num * 10 + *str - '0';
			str++;
		}
		if ((num > 2147483648 || (num == 2147483648 && neg != -1))
			|| check_duplicate(list, num * neg))
			return (1);
		add_rear(list, num * neg, 0);
		while (*str == ' ')
			str++;
	}
	return (0);
}

int	parsing(int argc, char **argv, t_list *list)
{
	int		idx;
	int		j;
	char	*str;

	idx = 0;
	while (++idx < argc)
	{
		str = argv[idx];
		j = -1;
		while (str[++j])
			if (!ft_isdigit(str[j])
				&& str[j] != ' ' && str[j] != '-' && str[j] != '+')
				return (1);
	}
	idx = 0;
	while (++idx < argc)
	{
		j = -1;
		str = argv[idx];
		if (check_num(str, list))
			return (1);
	}
	return (0);
}

void	indexing(t_list *list)
{
	int		size;
	int		j;
	long	max;
	t_node	*tmp;
	t_node	*max_node;

	size = list->size;
	while (size--)
	{
		tmp = list->f;
		max_node = tmp;
		max = -2147483649;
		j = 0;
		while (tmp)
		{
			if (tmp->data > max && tmp->idx == 0)
			{
				max = tmp->data;
				max_node = tmp;
			}
			tmp = tmp->next;
		}
		max_node->idx = size;
	}
}

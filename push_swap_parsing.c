/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:26:55 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/15 17:29:54 by jimchoi          ###   ########.fr       */
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

int	check_num(char *str, t_list *list)
{
	long	num;
	char	neg;

	while (*str)
	{
		num = 0;
		while (*str == ' ' || *str == '-')
		{
			neg = *str;
			str++;
		}	
		while ('0' <= *str && *str <= '9')
		{
			num = num * 10 + *str - '0';
			str++;
		}
		if (neg == '-')
			num = -num;
		if ((num > 2147483647 || num < -2147483648)
			|| check_duplicate(list, num))
			return (1);
		add_rear(list, num, 0);
		neg = 0;
	}
	return (0);
}

int	parsing(int argc, char **argv, t_list *list)
{
	int		idx;
	int		j;
	char	*str;

	idx = 1;
	while (idx < argc)
	{
		str = argv[idx];
		j = -1;
		while (str[++j])
		{
			if (('0' > str[j] || str[j] > '9')
				&& str[j] != ' ' && str[j] != '-')
				return (1);
		}	
		idx++;
	}
	idx = 0;
	while (++idx < argc)
	{
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
	int		max;
	t_node	*tmp;
	t_node	*max_node;

	size = list->size;
	while (size--)
	{
		tmp = list->front;
		max_node = tmp;
		max = -2147483648;
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
			tmp = list->front;
}

int	find_max(t_list *A)
{
	t_node	*tmp;
	long	max;
	long	num;

	max = 0;
	tmp = A->front;
	while (tmp)
	{	
		num = tmp->idx;
		if (num > max)
			max = num;
		tmp = tmp->next;
	}
	return (max);
}

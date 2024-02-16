/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:26:55 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/16 21:18:13 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_list *list, int num, char *str)
{
	t_node	*tmp;

	// if (!ft_isdigit(*str))
	// 	return (1);
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
	// printf("s = %s\n", str);
	long	num;
	char	neg;
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '-')
		{
			neg = '-';
			str++;
		}
		if (!ft_isdigit(*str))
			return (1);
		num = 0;
		while (ft_isdigit(*str))
		{
			num = num * 10 + *str - '0';
		// printf(" = %ld \n", num);
			str++;
		}
		if (neg == '-')
			num = -num;
		if ((num > 2147483647 || num < -2147483648)
			|| check_duplicate(list, num, str))
			{
				// printf("num =%ld\n", num);
			return (1);
			}
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
		while (str[++j])
		{
			while (str[j] == ' ')
				j++;
			if (str[j] == '+')
				j++;
			if (check_num(str + j, list))
				return (1);
			if (str[j] == '-')
				j++;
		}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:26:52 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/08 21:27:29 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_leaks(void)
{
	system("leaks a.out");
}


int check_duplicate(t_list *list, int num)
{
	t_node    *tmp;

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

	while(*str)
	{
		num = 0;
		while(*str == ' ' || *str == '-')
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
		if ((num > 2147483647 || num < -2147483648) && check_duplicate(list, num))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		add_rear(list, num, 0);
		neg = 0;
	}
		return (0);
}

int parsing(int argc, char **argv, t_list *list)
{
	int	idx;
	char *str;
	int j;

	idx = 1;
	while (idx < argc)
	{
		str = argv[idx];
		j = -1;
		while (str[++j])
		{
			if (('0' > str[j] || str[j] > '9') && str[j] != ' ' && str[j] != '-') //ㅅㅜㅅ자가 아닌데 공백도 아니면 끝
			{
				write(1, "Error\n", 6);
				return (1);
			}
		}	
		if (check_num(str, list))
            return (1);
		idx++;
	}

	return (0);
}


void push_swap(t_list *A, t_list *B, int max)
{
	t_node	*tmp;

	int i = 1;
	int j = 0;
	int n;
	while(max--)
	{
		tmp = A->front;
		j = -1;
		n = A->size;
		while(++j < n)
		{
			if ((tmp->data / i) % 2 == 1)
				ra(A, *tmp);
			else
				pb(A, B, *tmp);
			tmp = A->front;
		}
		j = -1;
		n = B->size;
		while(++j < n)
			pa(A, B, *(B->front));
		i *= 2;
	}
}

int	find_max(t_list *A)
{
	t_node    *tmp;
    long        max;
	long num;
    max = 0;
    tmp = A->front;
    while(tmp)
    {	
		num = tmp->idx;
        if (num > max)
            max = num;
        tmp = tmp->next;
    }
    return (max);
}

void indexing(t_list *list)
{
	int	size = list->size;
	int i = 0;
	int j = 0;
	t_node *tmp;
	t_node *max_node;

	while(i < size)
	{
		tmp = list->front;
		max_node = tmp;
	int max = -2147483648;
	j = 0;
		while(j < size)
		{
			if(tmp->data > max && tmp->idx == 0)
			{
				max = tmp->data;
                max_node = tmp;
			}
            tmp = tmp->next;
			j++;
		}
			max_node->idx = size - i;
		i++;
	}
	

}

int main(int argc, char **argv)
{

	t_list	*list = malloc(sizeof(t_list));
	t_list	*list_B = malloc(sizeof(t_list));
	t_node	*tmp;

	list->size = 0;
	int	i = 0;
	long	max = 0;
	
	if(parsing(argc, argv, list) && list->size == 1)
		return (0);
	max = find_max(list);
	while(max > 0)
	{
		max = max / 2;
		i++;
	}
	indexing(list);
	tmp = list->front;
	int j = 1;
	while(tmp->next != 0)
	{
		if(tmp->data < tmp->next->data)
			j++;
		tmp = tmp->next;
	}
	if (j == list->size)
		return (0);

	// if (list->size < 6)
    // {
	// 	small_case_push_swap(list, list_B, i)
	// }
	push_swap(list, list_B, i);

	i = 0;
	while (list->size > 0)
	{
		del_front(list);
		i++;
	}
	free(list);
	free(list_B);
	// atexit(check_leaks);
}
// 1 11111 11111 11111 11111 11111 11111
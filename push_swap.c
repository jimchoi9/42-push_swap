/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:26:52 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/06 22:39:14 by jimchoi          ###   ########.fr       */
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


int	check_num(char *str, t_list *list, long *max)
{
	long	num;
	int		neg = 0;

	while(*str)
	{
		while(*str == ' ')
			str++;
		num = 0;
		if(*str == '-')
		{
			neg = 1;
            str++;
		}
		while ('0' <= *str && *str <= '9')
		{
			num = num * 10 + *str - '0';
			str++;
		}
		if (num > *max)
			*max = num;
		if (neg == 1)
			num = -num;
		if (num > 2147483647 || num < -2147483648)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		if (check_duplicate(list, num))
		{
            write(1, "Error\n", 6);
            return (1);
        }
		add_rear(list, num);
		neg = 0;
	}
		return (0);
}

int parsing(int argc, char **argv, t_list *list, long *max)
{
	int	idx;
	char *str;
	int j;
	int num;

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
		if (check_num(str, list, max))
            return (1);
		idx++;
	}
	// printf("max in pasing %d\n", *max);
	return (0);
}


void push_swap(t_list *A, t_list *B, int max)
{
	t_node	*tmp;

	int i = 1;
	int j = 0;
	int n;
	tmp = A->front;
	while (tmp->next != 0)
	{
		
		tmp = tmp->next;
	}
	// int sd_len = i;
	while(max--)
	{
		// if (sd_len > 20)
		// 	break;
		tmp = A->front;
		// printf ("rea:%d size::%d || %d\n", j, n, A->size);
		j = 0;
		n = A->size;
		while(j < n)
		{
			// if (tmp->data > tmp->next->data)
			// 	sa(A);
			if ((tmp->data / i) % 2 == 1)
				ra(A, tmp->data);
			else
				pb(A, B, tmp->data);
			tmp = A->front;
			j++;
		}
		j = 0;
		n = B->size;
		while(j < n)
		{
			pa(A, B, B->front->data);
			j++;
		}
		i *= 2;
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
	if(parsing(argc, argv, list, &max))
		return (1);

	// tmp = list->front;
	// while(tmp->next != 0)
	// {
	// 	printf("%d ",tmp->data);
	// 	tmp = tmp->next;
	// }


	if (list->size == 1)
		return 0;
	while(max > 0)
	{
		max = max / 2;
		i++;
	}
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
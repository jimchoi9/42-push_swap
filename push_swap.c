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

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

void check_leaks(void)
{
	system("leaks a.out");
}
typedef struct	s_node {
	int            data;
	struct s_node    *next; // 두ㅣ
	struct s_node    *prev; //앞
	int					idx;
}	t_node;

typedef struct	s_list{
	t_node        *front;
	t_node        *rear;
	int        size;
	char		name;
}	t_list;

void add_front(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		new_node->next = list->front;
		list->front->prev = new_node;
		list->front = new_node;
	}
	list->size++;
	new_node->idx = list->size;
}

void add_rear(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		list->rear->next = new_node;
		new_node->prev = list->rear;
		list->rear = new_node;
	}
	list->size++;
}

void del_front(t_list *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->front;
		list->front = list->front->next;
		list->front->prev = NULL;
		free(tmp);
	}
	else
		free(list->front);
	list->size--;
}

void del_rear(t_list *list)
{
	t_node    *tmp;

	if (list->size > 1)
	{
		tmp = list->rear;
		list->rear = list->rear->prev;
		list->rear->next = NULL;
		free(tmp);
	}
	else
		free(list->rear);
	list->size--;
}

int checkDuplicate(t_list *list, int num)
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
	int		neg;

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
		if (checkDuplicate(list, num))
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
	return (0);
}

void	sa(t_list *a)
{
	int	data;

	data = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = data;
	write(1, "sa\n", 3);
}
void	sb(t_list *b)
{
	int	data;

	data = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = data;
	write(1, "sb\n", 3);
}
void	ss(t_list *a ,t_list *b)
{
	int	data;
	int	data2;

	data = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = data;
	data2 = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = data2;
	write(1, "ss\n", 3);
}

void ra(t_list *a, int data)
{
	write(1, "ra\n", 3);
	add_rear(a, data);
	del_front(a);

}

void rb(t_list *b, int data)
{
	write(1, "rb\n", 3);
	add_rear(b, data);
	del_front(b);

}
void rr(t_list *a, t_list *b, int data, int data2)
{
	write(1, "rr\n", 3);
	add_rear(a, data);
	del_front(a);
	add_rear(b, data2);
	del_front(b);

}
void	rra(t_list *a)
{
	write(1, "rra\n", 4);
	add_front(a, a->rear->data);
	del_rear(a);
}
void    rrb(t_list *b)
{
	write(1, "rrb\n", 4);
	add_front(b, b->rear->data);
	del_rear(b);
}

void	rrr(t_list *a, t_list *b)
{
	write(1, "rrr\n", 4);
	add_front(a, a->rear->data);
	add_front(b, b->rear->data);
	del_rear(a);
	del_rear(b);
}

void pb(t_list *a, t_list *b, int data)
{
	write(1, "pb\n", 3);
	add_front(b, data);
	del_front(a);
}

void pa(t_list *a, t_list *b, int data)
{
	write(1, "pa\n", 3);
	add_front(a,data);
	del_front(b);
}

#include <stdio.h>
void push_swap(t_list *A, t_list *B, int max)
{
	t_node	*tmp;

	int i = 2;
	int j = 0;
	int n;
		n = A->size;
	tmp = A->front;
	while (tmp->next != 0)
	{
		
		tmp = tmp->next;
	}
	int sd_len = i;
	while(1)
	{
		if (i > 20)
			break;
		tmp = A->front;
		printf ("rea:%d size::%d || %d\n", j, n, A->size);
		j = 0;
		while(j < n)
		{			// if (tmp->data > tmp->next->data)
			// 	sa(A);
			if ((tmp->data % i) / (i / 2) == 1)
				ra(A, tmp->data);
			else
				pb(A, B, tmp->data);
			tmp = A->front;
			j++;
		}
		j = 0;
		// tmp = B->front;
		// while(tmp != 0)
		while(1)
		{
			if (B->size == 0)
				break;
			pa(A, B, B->front->data);
		}
		i += 2;
	}
}

int main(int argc, char **argv)
{

	t_list	*list = malloc(sizeof(t_list));
	t_list	*list_B = malloc(sizeof(t_list));
	t_node	*tmp;

	list->size = 0;
	int	i = 2;
	long	max;
	if(parsing(argc, argv, list, &max))
		return (1);
	tmp = list->front;
	while (tmp)
	{

		tmp = tmp->next;
	}
	i = 2;
	if (list->size == 1)
		return 0;
	while(max > 0)
	{
		max = max / 2;
	// if (max > 0)
		i += 1;
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
	// printf("%d, %d", j, list->size);
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
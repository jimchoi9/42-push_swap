/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:18 by jimchoi           #+#    #+#             */
/*   Updated: 2024/01/11 21:50:12 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_node {
	int            data;
	struct s_node    *prev; //앞
	struct s_node    *next; // 두ㅣ
	int					idx;
}	t_node;

typedef struct	s_list{
	t_node        *front;
	t_node        *rear;
	int        lsize;
}	t_list;

typedef struct s_stack
{
	int		size;
	t_list	a;
	t_list	b;
} t_stack;

void add_front(t_list	*list, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->lsize == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		new_node->next = list->front;
		list->front->prev = new_node;
		list->front = new_node;
	}
	list->lsize++;
	new_node->idx = list->lsize;
}

void add_rear(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->lsize == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		list->rear->next = new_node;
		new_node->prev = list->rear;
		list->rear = new_node;
	}
	list->lsize++;
}

void del_front(t_list *list)
{
	t_node	*tmp;

	if (list->lsize > 1)
	{
		tmp = list->front;
		list->front = list->front->next;
		list->front->prev = NULL;
		free(tmp);
	}
	else
		free(list->front);
	list->lsize--;
}

void del_rear(t_list *list)
{
	t_node    *tmp;

	if (list->lsize > 1)
	{
		tmp = list->rear;
		list->rear = list->rear->prev;
		list->rear->next = NULL;
		free(tmp);
	}
	else
		free(list->rear);
	list->lsize--;
}

void	swap(t_node *a, t_node *b) //12 swap
{

	int tmp;

	tmp = a->idx;
	a->idx = b->idx;
	b->idx = tmp;
}

// void	rotate(t_list *);`
void push(t_list *from, t_list *to)
{
	add_front(to, from->front->data);
	del_front(from);
}

void selection_sort(t_list *list)
{
	int        i;
	int        j;
    t_node    *tmp;
	int		tnum;

    j = 0;
    while (j < list->lsize - 1)
    {
		i = 0;
        tmp = list->front;
        while (i < list->lsize - 1)
        {
            if (tmp->data > tmp->next->data)
                {
					// printf("%d %d \n", tmp->data, tmp->next->data);
					// tnum = tmp->data;
					// tmp->data = tmp->next->data;
					// tmp->next->data = tnum;
					
				}
            tmp = tmp->next;
            i++;
        }
		j++;
    }
}

int main()
{
	int arr[10] = {5, 3, 6234234, 7, 2, 8234, 9, 0, 1, 41231};

    t_list    *list= malloc(sizeof(t_list));
	t_node    *tmp;

	for(int i = 0; i < 10; i++)
	{
		add_front(list, arr[i]);
	}
	tmp = list->front;
	for(int j = 0; j < list->lsize; j++)
	{
		printf("list[%d] = %d\n", tmp->idx, tmp->data);
		tmp = tmp->next;
	}
	selection_sort(list);

	tmp = list->front;
	for(int j = 0; j < list->lsize; j++)
	{
		printf("list[%d] = %d\n",tmp->data, tmp->idx);
		tmp = tmp->next;
	}


}
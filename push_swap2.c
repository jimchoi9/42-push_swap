/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:59:21 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/16 12:06:59 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_list *list, int data, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->idx = idx;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0)
	{
		list->front = new_node;
		list->rear = new_node;
	}
	else
	{
		new_node->next = list->front;
		list->front->prev = new_node;
		list->front = new_node;
	}
	list->size++;
	new_node->idx = list->size;
}

void	add_rear(t_list *list, int data, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->idx = idx;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0)
	{
		list->front = new_node;
		list->rear = new_node;
	}
	else
	{
		list->rear->next = new_node;
		new_node->prev = list->rear;
		list->rear = new_node;
	}
	list->size++;
}

void	del_front(t_list *list)
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

void	del_rear(t_list *list)
{
	t_node	*tmp;

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

void	sa(t_list *a)
{
	int	data;
	int	idx;

	data = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = data;
	idx = a->front->idx;
	a->front->idx = a->front->next->idx;
	a->front->next->idx = idx;
	write(1, "sa\n", 3);
}

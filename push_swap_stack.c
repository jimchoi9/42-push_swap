/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:59:21 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/19 16:34:06 by jimchoi          ###   ########.fr       */
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
		list->f = new_node;
		list->r = new_node;
	}
	else
	{
		new_node->next = list->f;
		list->f->prev = new_node;
		list->f = new_node;
	}
	list->size++;
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
		list->f = new_node;
		list->r = new_node;
	}
	else
	{
		list->r->next = new_node;
		new_node->prev = list->r;
		list->r = new_node;
	}
	list->size++;
}

void	del_front(t_list *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->f;
		list->f = list->f->next;
		list->f->prev = NULL;
		free(tmp);
	}
	else
		free(list->f);
	list->size--;
}

void	del_rear(t_list *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->r;
		list->r = list->r->prev;
		list->r->next = NULL;
		free(tmp);
	}
	else
		free(list->r);
	list->size--;
}

void	sa(t_list *a)
{
	int	data;
	int	idx;

	data = a->f->data;
	a->f->data = a->f->next->data;
	a->f->next->data = data;
	idx = a->f->idx;
	a->f->idx = a->f->next->idx;
	a->f->next->idx = idx;
	write(1, "sa\n", 3);
}

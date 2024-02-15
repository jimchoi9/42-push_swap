/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:39:24 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/15 18:04:19 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *b)
{
	int	data;
	int	idx;

	data = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = data;
	idx = b->front->idx;
	b->front->idx = b->front->next->idx;
	b->front->next->idx = idx;
	write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	int	data;
	int	data2;
	int	idx;
	int	idx2;

	data = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = data;
	data2 = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = data2;
	idx = a->front->idx;
	a->front->idx = a->front->next->idx;
	a->front->next->idx = idx;
	idx2 = b->front->idx;
	b->front->idx = b->front->next->idx;
	b->front->next->idx = idx2;
	write(1, "ss\n", 3);
}

void	ra(t_list *a, t_node tmp)
{
	write(1, "ra\n", 3);
	add_rear(a, tmp.data, tmp.idx);
	del_front(a);
}

void	rb(t_list *b, t_node tmp)
{
	write(1, "rb\n", 3);
	add_rear(b, tmp.data, tmp.idx);
	del_front(b);
}

void	rr(t_list *a, t_list *b, t_node tmp1, t_node tmp2)
{
	write(1, "rr\n", 3);
	add_rear(a, tmp1.data, tmp1.idx);
	del_front(a);
	add_rear(b, tmp2.data, tmp2.idx);
	del_front(b);
}

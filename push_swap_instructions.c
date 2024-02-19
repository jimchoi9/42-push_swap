/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:39:24 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/19 16:33:09 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *b)
{
	int	data;
	int	idx;

	data = b->f->data;
	idx = b->f->idx;
	b->f->data = b->f->next->data;
	b->f->idx = b->f->next->idx;
	b->f->next->data = data;
	b->f->next->idx = idx;
	write(1, "sb\n", 3);
}

void	ra(t_list *a, t_node tmp)
{
	write(1, "ra\n", 3);
	add_rear(a, tmp.data, tmp.idx);
	del_front(a);
}

void	rra(t_list *a)
{
	write(1, "rra\n", 4);
	add_front(a, a->r->data, a->r->idx);
	del_rear(a);
}

void	pb(t_list *a, t_list *b, t_node tmp)
{
	write(1, "pb\n", 3);
	add_front(b, tmp.data, tmp.idx);
	del_front(a);
}

void	pa(t_list *a, t_list *b, t_node tmp)
{
	write(1, "pa\n", 3);
	add_front(a, tmp.data, tmp.idx);
	del_front(b);
}

// void	rb(t_list *b, t_node tmp)
// {
// 	write(1, "rb\n", 3);
// 	add_rear(b, tmp.data, tmp.idx);
// 	del_front(b);
// }

// void	rr(t_list *a, t_list *b, t_node tmp1, t_node tmp2)
// {
// 	write(1, "rr\n", 3);
// 	add_rear(a, tmp1.data, tmp1.idx);
// 	del_front(a);
// 	add_rear(b, tmp2.data, tmp2.idx);
// 	del_front(b);
// }

// void	ss(t_list *a, t_list *b)
// {
// 	int	data;
// 	int	data2;
// 	int	idx;
// 	int	idx2;

// 	data = a->front->data;
// 	a->front->data = a->front->next->data;
// 	a->front->next->data = data;
// 	data2 = b->front->data;
// 	b->front->data = b->front->next->data;
// 	b->front->next->data = data2;
// 	idx = a->front->idx;
// 	a->front->idx = a->front->next->idx;
// 	a->front->next->idx = idx;
// 	idx2 = b->front->idx;
// 	b->front->idx = b->front->next->idx;
// 	b->front->next->idx = idx2;
// 	write(1, "ss\n", 3);
// }

// void	rrb(t_list *b)
// {
// 	write(1, "rrb\n", 4);
// 	add_front(b, b->rear->data, b->rear->idx);
// 	del_rear(b);
// }

// void	rrr(t_list *a, t_list *b)
// {
// 	write(1, "rrr\n", 4);
// 	add_front(a, a->rear->data, a->rear->idx);
// 	add_front(b, b->rear->data, b->rear->idx);
// 	del_rear(a);
// 	del_rear(b);
// }
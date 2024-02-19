/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:39:24 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/19 18:47:51 by jimchoi          ###   ########.fr       */
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

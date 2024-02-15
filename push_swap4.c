/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:41:40 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/15 17:43:03 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *a)
{
	write(1, "rra\n", 4);
	add_front(a, a->rear->data, a->rear->idx);
	del_rear(a);
}

void	rrb(t_list *b)
{
	write(1, "rrb\n", 4);
	add_front(b, b->rear->data, b->rear->idx);
	del_rear(b);
}

void	rrr(t_list *a, t_list *b)
{
	write(1, "rrr\n", 4);
	add_front(a, a->rear->data, a->rear->idx);
	add_front(b, b->rear->data, b->rear->idx);
	del_rear(a);
	del_rear(b);
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

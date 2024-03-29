/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:26:52 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/26 11:22:51 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int max)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		n;

	i = 0;
	while (max--)
	{
		tmp = a->f;
		j = -1;
		n = a->size;
		while (++j < n)
		{
			if (((tmp->idx >> i) & 1) == 1)
				ra(a, *tmp);
			else
				pb(a, b, *tmp);
			tmp = a->f;
		}
		j = -1;
		n = b->size;
		while (++j < n)
			pa(a, b, *(b->f));
		i++;
	}
}

void	small_case_push_swap(t_list *a, t_list *b, int n)
{
	if (n > 3)
	{
		while (n--)
		{
			if (a->f->idx < 2)
				pb(a, b, *(a->f));
			else
				ra(a, *(a->f));
		}
	}
	if ((a->f->data < a->f->next->data && a->f->data < a->r->data)
		|| (a->f->data > a->r->data && a->f->data > a->f->next->data))
		ra(a, *a->f);
	if (a->f->data > a->f->next->data)
		sa(a);
	if (a->r->data < a->f->data)
		rra(a);
	if (b->size != 0)
	{
		if (b->f->data < b->f->next->data)
			sb(b);
		pa(a, b, *(b->f));
		pa(a, b, *(b->f));
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		max;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	stack_a->size = 0;
	stack_b->size = 0;
	if (argc < 2)
		exit (1);
	if (parsing(argc, argv, stack_a))
		handle_error();
	indexing(stack_a);
	max = find_max(stack_a);
	if (check_sorted(stack_a))
		exit (0);
	if (stack_a->size < 6 && stack_a->size != 0)
		small_case_push_swap(stack_a, stack_b, stack_a->size);
	else
		push_swap(stack_a, stack_b, max);
	while (stack_a->size > 0)
		del_front(stack_a);
	free(stack_a);
	free(stack_b);
}

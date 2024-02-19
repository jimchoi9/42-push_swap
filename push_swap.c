/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:26:52 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/19 17:21:51 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int max)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		n;

	i = 1;
	while (max--)
	{
		tmp = a->f;
		j = -1;
		n = a->size;
		while (++j < n)
		{
			if ((tmp->idx / i) % 2 == 1)
				ra(a, *tmp);
			else
				pb(a, b, *tmp);
			tmp = a->f;
		}
		j = -1;
		n = b->size;
		while (++j < n)
			pa(a, b, *(b->f));
		i *= 2;
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

int	check_sorted(t_list *stack_a)
{
	t_node	*tmp;
	int		j;

	j = 1;
	tmp = stack_a->f;
	while (tmp->next != 0)
	{
		if (tmp->data < tmp->next->data)
			j++;
		tmp = tmp->next;
	}
	if (j == stack_a->size)
		return (1);
	return (0);
}

// void	printlist(t_list *stack_a)
// {
// 	t_node	*tmp;

// 	tmp = stack_a->f;
// 	while (tmp)
// 	{
// 		printf("A[%d] = %d\n", tmp->idx, tmp->data);
// 		tmp = tmp->next;
// 	}
// }
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		max;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	stack_a->size = 0;
	stack_b->size = 0;
	if (!(argv[1]) || !argv[1][0])
		exit (1);
	if (parsing(argc, argv, stack_a))
		handle_error();
	indexing(stack_a);
	max = find_max(stack_a);
	if (check_sorted(stack_a))
		exit (0);
	if (stack_a->size < 6)
		small_case_push_swap(stack_a, stack_b, stack_a->size);
	else
		push_swap(stack_a, stack_b, max + 1);
	while (stack_a->size > 0)
		del_front(stack_a);
	free(stack_a);
	free(stack_b);
}
// atexit(check_leaks);
// void	check_leaks(void)
// {
// 	system("leaks push_swap");
// }
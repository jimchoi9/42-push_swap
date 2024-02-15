/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:26:52 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/15 18:08:03 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks push_swap");
}

void	push_swap(t_list *A, t_list *B, int max)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		n;

	i = 1;
	while (max--)
	{
		tmp = A->front;
		j = -1;
		n = A->size;
		while (++j < n)
		{
			if ((tmp->data / i) % 2 == 1)
				ra(A, *tmp);
			else
				pb(A, B, *tmp);
			tmp = A->front;
		}
		j = -1;
		n = B->size;
		while (++j < n)
			pa(A, B, *(B->front));
		i *= 2;
	}
}

void	small_case_push_swap(t_list *a, t_list *b)
{
	int	n;

	n = a->size;
	if (n <= 3)
	{
		if ((a->front->data < a->front->next->data
				&& a->front->data < a->rear->data)
			|| (a->front->data > a->rear->data
				&& a->front->data > a->front->next->data))
			ra(a, *a->front);
		if (a->front->data > a->front->next->data)
			sa(a);
		if (a->rear->data < a->front->data)
			rra(a);
	}
	else
	{
		while (n--)
		{
			if (a->front->idx < 2)
				pb(a, b, *(a->front));
			else
				ra(a, *(a->front));
		}
		if ((a->front->data < a->front->next->data
				&& a->front->data < a->rear->data)
			|| (a->front->data > a->rear->data
				&& a->front->data > a->front->next->data))
			ra(a, *a->front);
		if (a->front->data > a->front->next->data)
			sa(a);
		if (a->rear->data < a->front->data)
			rra(a);
		if (b->front->data < b->front->next->data)
			sb(b);
		pa(a, b, *(b->front));
		pa(a, b, *(b->front));
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_node	*tmp;
	int		i;
	long	max;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	stack_a->size = 0;
	i = 0;
	if (!(*argv[1]) || !argv[1][0])
		exit (1);
	if (parsing(argc, argv, stack_a) || stack_a->size < 1)
	{
		write(2, "Error\n", 6);
		atexit(check_leaks);
		exit (1);
	}
	indexing(stack_a);
	max = find_max(stack_a);
	while (max > 0)
	{
		max = max / 2;
		i++;
	}
	tmp = stack_a->front;
	int j = 1;
	while(tmp->next != 0)
	{
		if(tmp->data < tmp->next->data)
			j++;
		tmp = tmp->next;
	}
	if (j == stack_a->size)
		return (0);
	if (stack_a->size < 6)
		small_case_push_swap(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b, i);

	i = 0;
	while (stack_a->size > 0)
	{
		del_front(stack_a);
		i++;
	}
	free(stack_a);
	free(stack_b);
	atexit(check_leaks);
}
// 1 11111 11111 11111 11111 11111 11111

// 아무것도 없었을때
// ""
// 하나 있을때 
// 정렬되어 있었을때 ra,rb같은 명령어 나오면 안됨
// 1 - 가 정렬되버림
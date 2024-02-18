/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:26:52 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/16 21:10:30 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	check_leaks(void)
// {
// 	system("leaks push_swap");
// }
void	push_swap(t_list *a, t_list *b, int max)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		n;

	i = 1;
	while (max--)
	{
		tmp = a->front;
		j = -1;
		n = a->size;
		while (++j < n)
		{
			if ((tmp->data / i) % 2 == 1)
				ra(a, *tmp);
			else
				pb(a, b, *tmp);
			tmp = a->front;
		}
		j = -1;
		n = b->size;
		while (++j < n)
			pa(a, b, *(b->front));
		i *= 2;
	}
}

void	small_case_push_swap(t_list *a, t_list *b)
{
	int	n;

	n = a->size;
	if (n > 3)
		while (n--)
		{
			if (a->front->idx < 2)
				pb(a, b, *(a->front));
			else
				ra(a, *(a->front));
		}
	if ((a->F->data < a->F->N->data && a->F->data < a->R->data) 
		|| (a->F->data > a->R->data && a->F->data > a->F->N->data))
		ra(a, *a->F);
	if (a->front->data > a->front->next->data)
		sa(a);
	if (a->rear->data < a->front->data)
		rra(a);
	if (b->size != 0)
	{
		if (b->front->data < b->front->next->data)
			sb(b);
		pa(a, b, *(b->front));
		pa(a, b, *(b->front));
	}
}

int	check_sorted(t_list *stack_a)
{
	t_node	*tmp;
	int		j;

	j = 1;
	tmp = stack_a->front;
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

void	printlist(t_list *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->front;
	while(tmp)
	{
		printf("%d [%d]\n", tmp->data, tmp->idx);
        tmp = tmp->next;
	}
}
int	handle_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
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
	if (!(argv[1]) || !argv[1][0])
		exit (1);
	if (parsing(argc, argv, stack_a))
		handle_error();
	indexing(stack_a);
	max = find_max(stack_a);
	if (check_sorted(stack_a))
		exit (0);
	// printlist(stack_a);
	if (stack_a->size < 6)
		small_case_push_swap(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b, max);
	while (stack_a->size > 0)
		del_front(stack_a);
	free(stack_a);
	free(stack_b);
}
	// atexit(check_leaks);
// 1 2 - 3 
// + ㅈㅓㄱ요ㅇ
/*
ARG="4 67 -3 8 -2 1"; ./push_swap $ARG | ./checker_Mac $ARG 정렬실패
ARG="4 67 -3 8 -2 1"; ./push_swap $ARG
ARG="3 5 0 4 1 2"; ./push_swap $ARG | ./checker_Mac $ARG 정렬됨
ra
ra
pb
ra
pb
ra
rra
sb
pa
pa

*/
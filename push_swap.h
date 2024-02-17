/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:43:42 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/16 20:55:05 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				idx;
}	t_node;

typedef struct s_stack{
	t_node		*front;
	t_node		*rear;
	int			size;
	char		name;
}	t_list;

void	add_front(t_list *list, int data, int idx);
void	add_rear(t_list *list, int data, int idx);
void	del_front(t_list *list);
void	del_rear(t_list *list);
int		check_duplicate(t_list *list, int num);
int		check_num(char *str, t_list *list);
int		parsing(int argc, char **argv, t_list *list);
void	indexing(t_list *list);
int		find_max(t_list *stack_a);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	ra(t_list *a, t_node tmp);
void	rb(t_list *b, t_node tmp);
void	rr(t_list *a, t_list *b, t_node tmp1, t_node tmp2);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b, t_node tmp);
void	pa(t_list *a, t_list *b, t_node tmp);
void	push_swap(t_list *A, t_list *B, int max);



void	printlist(t_list *stack_a);
#endif
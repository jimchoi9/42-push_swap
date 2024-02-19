/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:43:42 by jimchoi           #+#    #+#             */
/*   Updated: 2024/02/19 18:47:23 by jimchoi          ###   ########.fr       */
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
	t_node		*f;
	t_node		*r;
	int			size;
	char		name;
}	t_list;

void	push_swap(t_list *A, t_list *B, int max);
void	small_case_push_swap(t_list *a, t_list *b, int n);
int		check_num(char *str, t_list *list);
int		parsing(int argc, char **argv, t_list *list);
void	indexing(t_list *list);
void	add_front(t_list *list, int data, int idx);
void	add_rear(t_list *list, int data, int idx);
void	del_front(t_list *list);
void	del_rear(t_list *list);
int		check_duplicate(t_list *list, int num);
int		is_op(char *str, int *neg);
int		find_max(t_list *stack_a);
int		check_sorted(t_list *stack_a);
void	handle_error(void);
void	sa(t_list *a);
void	sb(t_list *b);
void	ra(t_list *a, t_node tmp);
void	rra(t_list *a);
void	pb(t_list *a, t_list *b, t_node tmp);
void	pa(t_list *a, t_list *b, t_node tmp);

#endif
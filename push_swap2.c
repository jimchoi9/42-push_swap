#include "push_swap.h"

void add_front(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		new_node->next = list->front;
		list->front->prev = new_node;
		list->front = new_node;
	}
	list->size++;
	new_node->idx = list->size;
}

void add_rear(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		list->rear->next = new_node;
		new_node->prev = list->rear;
		list->rear = new_node;
	}
	list->size++;
}

void del_front(t_list *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->front;
		list->front = list->front->next;
		list->front->prev = NULL;
		free(tmp);
	}
	else
		free(list->front);
	list->size--;
}

void del_rear(t_list *list)
{
	t_node    *tmp;

	if (list->size > 1)
	{
		tmp = list->rear;
		list->rear = list->rear->prev;
		list->rear->next = NULL;
		free(tmp);
	}
	else
		free(list->rear);
	list->size--;
}


void	sa(t_list *a)
{
	int	data;

	data = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = data;
	write(1, "sa\n", 3);
}
void	sb(t_list *b)
{
	int	data;

	data = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = data;
	write(1, "sb\n", 3);
}
void	ss(t_list *a ,t_list *b)
{
	int	data;
	int	data2;

	data = a->front->data;
	a->front->data = a->front->next->data;
	a->front->next->data = data;
	data2 = b->front->data;
	b->front->data = b->front->next->data;
	b->front->next->data = data2;
	write(1, "ss\n", 3);
}

void ra(t_list *a, int data)
{
	write(1, "ra\n", 3);
	add_rear(a, data);
	del_front(a);

}

void rb(t_list *b, int data)
{
	write(1, "rb\n", 3);
	add_rear(b, data);
	del_front(b);

}
void rr(t_list *a, t_list *b, int data, int data2)
{
	write(1, "rr\n", 3);
	add_rear(a, data);
	del_front(a);
	add_rear(b, data2);
	del_front(b);

}
void	rra(t_list *a)
{
	write(1, "rra\n", 4);
	add_front(a, a->rear->data);
	del_rear(a);
}
void    rrb(t_list *b)
{
	write(1, "rrb\n", 4);
	add_front(b, b->rear->data);
	del_rear(b);
}

void	rrr(t_list *a, t_list *b)
{
	write(1, "rrr\n", 4);
	add_front(a, a->rear->data);
	add_front(b, b->rear->data);
	del_rear(a);
	del_rear(b);
}

void pb(t_list *a, t_list *b, int data)
{
	write(1, "pb\n", 3);
	add_front(b, data);
	del_front(a);
}

void pa(t_list *a, t_list *b, int data)
{
	write(1, "pa\n", 3);
	add_front(a,data);
	del_front(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:16:48 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/05/08 17:18:27 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_x(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		x;

	a = *stack_a;
	b = *stack_b;
	x = 0;
	while (a)
	{
		if (!b)
			pb(&a, &b);
		x = rot_double(&a, &b, find_max(a), find_max(b));
		if (x == -1)
			return ;
		pb(&a, &b);
		if (b->data < b->next->data)
			sb(&b);
	}
	pushback(&a, &b);
	*stack_a = a;
	*stack_b = b;
}

void	pushback(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	pa(&a, &b);
	while (b != NULL)
	{
		while (a->data < b->data)
		{
			if (a->next->data < a->data)
				sa(&a);
			ra(&a);
		}
		pa(&a, &b);
	}
	*stack_a = a;
	*stack_b = b;
}

void last_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		elements;
	
	a = *stack_a;
	b = *stack_b;
	elements = stack_size(a);
	if (elements <= 1)
		return ;
	part_sort(&a, 0, elements - 1);
	*stack_a = a;
	*stack_b = b;
}

void part_sort(t_list **stack, int low, int high)
{
	int pi;
	
	pi = 0;
	if (low < high) 
	{
		pi = partition(stack, low, high);
		part_sort(stack, low, pi - 1);
		part_sort(stack, pi + 1, high);
	}
}

int partition(t_list **stack, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = (*stack)->data;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if ((*stack)->data < pivot)
		{
			i++;
			sa(stack);
		}
		ra(stack);
		j++;
	}
	sa(stack);
	return (i + 1);
}

void bubble(t_list **stack_a, t_list **stack_b)
{
	int swap;
	int i;
	t_list *a;
	t_list *b;

	swap = 1;
	i = 0;
	a = *stack_a;
	b = *stack_b;
	while (swap == 1)
	{
		swap = 0;
		i = 0;
		while (i < stack_size(a) - 1)
		{
			if (a->data > a->next->data)
			{
				sa(&a);
				swap = 1;
				pb(&a, &b);
				rra(&a);
				pa(&a, &b);
			}
			ra(&a);
			i++;
		}
	}
	*stack_a = a;
	*stack_b = b;
}

void bubbleSort(t_list **head_ref)
{
	int swapped;
	t_list *ptr1;
	t_list *node;

	node = NULL;
	if (head_ref == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = *head_ref;
		if (ptr1->next != node)
		{
			if (ptr1->data > ptr1->next->data)
			{ 
				sa(&ptr1);
				swapped = 1;
			}
			rra(&ptr1);
		}
		node = ptr1;
	}
}

void selectionSort(t_list **head_ref)
{
	t_list  *ptr1;
	t_list  *ptr2;
	t_list  *min;

	ptr1 = *head_ref;
	while (ptr1->next)
	{
		min = ptr1;
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr2->data < min->data)
				min = ptr2;
			ptr2 = ptr2->next;
		}
		if (min != ptr1)
			sa(head_ref);
		ptr1 = ptr1->next;
	}
}

void sortedInsert(t_list **head_ref, t_list *new_node)
{
	t_list *current;

	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && current->next->data < new_node->data)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}

void insertionSort(t_list **head_ref)
{
	t_list  *sorted;
	t_list  *current;
	t_list  *next;

   sorted = NULL;
   current = *head_ref;
   next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = NULL;
		sortedInsert(&sorted, current);
		current = next;
	}
	*head_ref = sorted;
}

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		x;
	
	a = *stack_a;
	b = *stack_b;
	x = stack_size(*stack_a);
	while (x >= 0)
	{
		if (a && a->next && a->data < a->next->data)
			rra(&a);
		else
			pb(&a, &b);
		x--;
	}
	while (b)
	{
		rot_double(&a, &b, find_max(a), find_max(b));
		if (b->data < a->data)
		{
			while (b->data < a->data)
				ra(&a);
			pa(&a, &b);
		}
		else
		{
			rra(&a);
			pa(&a, &b);
		}
	}
	*stack_a = a;
	*stack_b = b;
}

void	parse_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		middle;
	int		max;
	
	a = *stack_a;
	b = *stack_b;
	max = find_max(*stack_a);
	middle = ((stack_size(a) / 2) + (stack_size(a) % 2));
	while (middle > 0)
	{
		if (a && a->data == max)
			ra(&a);
		else if (a && a->next && a->data < a->next->data)
		{
			pb(&a, &b);
			middle--;
		}
		else if (a && b && a->data < b->data)
		{
			pa(&a, &b);
			middle++;
		}
	}
	*stack_a = a;
	*stack_b = b;
	show(a);
	show(b);
}

void	list_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	while (stack_size(b) < 5)
		pb(&a, &b);
	sort_five(&b, &a);
	while (b)
	{
		rot_double(&a, &b, find_max(a), find_max(b));
		if (b->data < a->data)
		{
			if (b->data < a->data)
				ra(&a);
			pa(&a, &b);
		}
		else
		{
			rra(&a);
			pa(&a, &b);
		}
	}
	if (!is_sorted(a))
		list_sort(&a, &b);
	*stack_a = a;
	*stack_b = b;	
}

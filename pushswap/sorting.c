
#include "push_swap.h"

int	make_b_three(t_list **stack_a, t_list **stack_b)
{
	int		x;
	int		y;
	t_list	*a;
	t_list	*b;

	x = 0;
	y = 0;
	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		x++;
		b = b->next;
	}
	while (x < 3)
	{
		y += pb(&a, &b);
		x++;
	}
	*stack_a = a;
	*stack_b = b;
	return (y);
}

int	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		x;

	x = 0;
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	x += 2;
	ft_printf("pb\npb\n");
	x += sort_three(stack_a);
	if ((*stack_b)->data < (*stack_b)->next->data)
	{
		swap(stack_b);
		x++;
		ft_printf("sb\n");
	}
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	x += 2;
	ft_printf("pa\npa\n");
	return (x);
}

int	sort_more(t_list **stack_a, t_list **stack_b, int elements)
{
	t_list	*a;
	t_list	*b;
	int		c;

	a = *stack_a;
	b = *stack_b;
	c = 0;
	if (elements == 4)
	{
		while (a->data != find_min(a))
			c += ra(&a);
		c += pb(&a, &b);
		c += sort_three(&a);
		c += pa(&a, &b);
	}
	else
	{
		while (!is_sorted(&a))
		{
			c += ra(&a);
			c += make_b_three(&a, &b);
			c += sort_three(&b);
			c += pa(&a, &b);
			c += pa(&a, &b);
			c += pa(&a, &b);
		}
	}
	*stack_a = a;
	*stack_b = b;
	return (c);
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		counter;
	int		elements;

	a = *stack_a;
	b = *stack_b;
	counter = 0;
	elements = 0;
	if (!a)
		return (0);
	elements = stack_size(a);
	if (elements == 3)
		counter = sort_three(&a);
	else
		counter = sort_more(&a, &b, elements);
	*stack_a = a;
	*stack_b = b;
	//if b == 0:free b, else return error?
	return (counter);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		steps;

	steps = 0;
	min = find_min(*stack_a);
	max = find_max(*stack_a);
	while (!is_sorted(stack_a))
	{
		while (*stack_a && (*stack_a)->data != min && (*stack_a)->data != max)
		{
			steps++;
			pb(stack_a, stack_b);
			if (*stack_a && (*stack_a)->data == min)
			{
				steps++;
				ra(stack_a);
			}
			else if (*stack_a && (*stack_a)->data == max)
			{
				steps++;
				rra(stack_a);
			}
		}
		while (*stack_b && (*stack_b)->data != min && (*stack_b)->data != max)
		{
			steps++;
			pa(stack_b, stack_a);
			if (*stack_b && (*stack_b)->data == min)
			{
				steps++;
				rb(stack_b);
			}
			else if (*stack_b && (*stack_b)->data == max)
			{
				steps++;
				rrb(stack_b);
			}
		}
	}
	return (steps);
}

int	sort_three_a(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (s->next->data < s->next->next->data)
		return (x);
	else
	{
		if (s->data < s->next->next->data)
		{
			x = rra(&s);
			x = sa(&s);
		}
		else
			x = rra(&s);
	}
	*stack = s;
	return (x);
}

int	sort_three_b(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (s->next->data < s->next->next->data)
	{
		if (s->data < s->next->next->data)
			x = sa(&s);
		else
			x = ra(&s);
	}
	else
	{
		if (s->data > s->next->next->data)
		{
			x = sa(&s);
			x = rra(&s);
		}
	}
	*stack = s;
	return (x);
}

int	sort_three(t_list **stack)
{
	t_list	*s;
	int		x;

	s = *stack;
	x = 0;
	if (!s || !s->next || !s->next->next)
		return (0);
	if (s->data < s->next->data)
		x = sort_three_a(&s);
	else
		x = sort_three_b(&s);
	*stack = s;
	return (x);
}

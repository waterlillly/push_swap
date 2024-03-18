#include "push_swap.h"

int	sort_three(t_list *stack)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	x = stack->data;
	y = stack->next->data;
	z = stack->next->next->data;
	if (x && y && z)
	{
		if (x < y)
		{
			if (y < z)
			{
				if (x < z)
					return (1);
				else
					return (msg(4), 0);
			}
			else
			{
				if (x < z)
				{
					rra(stack);
					sa(stack);
					return (1);
				}
				else
				{
					rra(stack);
					return (1);
				}
			}
		}
		else
		{
			if (y < z)
			{
				if (x < z)
				{
					sa(stack);
					return (1);
				}
				else
				{
					ra(stack);
					return (1);
				}
			}
			else
			{
				if (x > z)
				{
					sa(stack);
					rra(stack);
					return (1);
				}
				else
					return (msg(4), 0);
			}
		}
	}
	return (0);
}

/*			
		if (a->data < a->prev->data)
		{
			if (a->data < a->next->data)
			{
				if (a->next->data < a->prev->data)
					ra(stack_a);
				else
					sa(stack_a);
			}
			else
				rra(stack_a);
		}
		else
		{
			if (a->data < a->next->data)
			{
				if (a->next->data < a->prev->data)
					return ;
				else
					dd_sort(stack_a, stack_b);
			}
			else
			{
				sa(stack_a);
				if (a->next->data < a->prev->data)
					rra(stack_a);
				else
					ra(stack_a);
			}
		}
	}
	if (b != 0)
	{
		pa(stack_a, stack_b);
		dd_sort(stack_a, stack_b);
	}
}
*/

int	ft_max(t_list *a)
{
	int		max;
	t_list	*cur;
	
	cur = a;
	max = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (max < cur->next->data)
			max = cur->next->data;
		cur = cur->next;
	}
	return (max);
}

int	next_min(t_list *a, int repeat, int min)
{
	t_list	*cur;
	int		new_min;

	cur = a;
	new_min = min + 1;
	if (repeat == 0)
		return (min);
	else if (repeat > 0)
	{
		while (cur != 0 && cur->next != 0)
		{
			if (new_min > min && new_min >= cur->data)
				new_min = cur->data;
			cur = cur->next;
		}
		return (next_min(a, repeat - 1, new_min));
	}
	else
		return (2147483647);
}

int	ft_min(t_list *a, int repeat)
{
	int		min;
	t_list	*cur;
	
	cur = a;
	min = cur->data;
	while (cur != 0 && cur->next != 0)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	if (repeat > 0)
		return (next_min(a, repeat, min));
	else
		return (min);
}

int	ft_mid(int ac, t_list *a)
{
	int		mid_min;
	int		x;

	mid_min = 0;
	x = (ac - 1) / 2;
	mid_min = ft_min(a, x);
	if (mid_min == 2147483647)
		return (msg(4), 0);
	else
		return (mid_min);
}
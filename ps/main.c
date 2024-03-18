#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	
	if (ac < 2 || (ac == 2 && av[1] == NULL))
		return (msg(1), 0);
	if (ac)
	if (is_sorted(ac, av) == 1)
	{
		a = NULL;
		a = stack(ac, av);
		if (!a)
			return (msg(5), ft_free(a), 0);
		if (ac > 4)
		{
			b = NULL;
			b = stack(ac, av);
			if (!b)
				return (ft_free(a), 0);
			sort_three(b);
		}
		if (check_sort(a) == 1 && !b)
			return (msg(6), ft_free(a), ft_free(b), 0);
		else
			return (msg(7), ft_free(a), ft_free(b), 0);
	}
	return (msg(1), 0);
}
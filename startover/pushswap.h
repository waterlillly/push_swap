/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:19:32 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/18 20:44:40 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
 #define PUSHSWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_list t_list;

typedef struct s_list
{
	int 	data;
	t_list	*next;
	t_list	*prev;
} 				t_list;

int		is_sorted(t_list *stack);
void	add(t_list **head, int value);
int		arr_len(char **input);
int		check_doubles(char **input, int x);
void	fill_stack(int ac, char **av, t_list **head);
int		ft_find(char *str, int c);
int		valid_arg(char **av);

/*from push_swap inprogress*/
int		sort_three(t_list **stack);
int		sort_three_b(t_list **stack);
int		sort_three_a(t_list **stack);
int		sort(t_list **stack_a);
int		sort_more(t_list **stack_a, int elements);
int		make_b_three(t_list **stack_a, t_list **stack_b);
int		stack_size(t_list *stack);
int		find_min(t_list *stack);
int		find_max(t_list *stack);

/*PUSWSWAP LIBRARY*/
void	swap(t_list **stack);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
void	rot(t_list **stack);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
void	rev_rot(t_list **stack);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

#endif

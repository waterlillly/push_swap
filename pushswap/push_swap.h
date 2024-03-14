/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:11:59 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/14 13:55:09 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_list	t_list;

typedef struct s_list
{
	int		data;
	t_list	*next;
	t_list	*prev;
}			t_list;

/*push_swap.c*/
t_list	**dd_sort(t_list **stack_a, t_list **stack_b);
int	ft_max(t_list **a);
int	next_min(t_list **a, int repeat, int min);
int	ft_min(t_list **a, int repeat);
int	ft_mid(int ac, t_list **a);

/*check_ups.c*/
void	ft_free(t_list **a, t_list **b);
void	error(int nbr);
int		check_doubles(int ac, int pos, t_list **stack);
int		check_sort(t_list **stack_a);
int		check_input(int ac, char **av);
int		first_check(int ac, char **av);

/*creations.c*/
void	add_head_node(t_list **stack, t_list *s, t_list *node, char id);
void	add_tail_node(t_list **stack, t_list *s, t_list *node);
void	insert_node(t_list **stack, t_list *s, t_list *node);
void	add_node(t_list **stack, int value, char id);
void	fill(t_list **stack, char **input, int len);
t_list	**stack(int	len);

/*operations.c*/
void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **dst, t_list **src);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	rot(t_list **stack);
void	rev_rot(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
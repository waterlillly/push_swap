/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:06:58 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/09 15:01:10 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_list	t_list;

typedef struct s_list
{
	int		data;
	t_list	*next;
	t_list	*prev;
}			t_list;

int		error(char c);
int		check_int_doubles(char **input);
t_list	*input(int ac, char **av, t_list *stack);
t_list	*create_node(int value);
int		max(t_list **a);
int		next_min(t_list **a, int repeat, int min);
int		min(t_list **a, int repeat);
int		mid(int ac, t_list **a);
t_list	*sort(t_list *a, t_list *b);
int		check_sort(t_list **a);
void	ft_free(t_list **a, t_list **b);
void	swap(t_list *x);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	push(t_list *dst, t_list *src);
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	rot(t_list *x);
void	rev_rot(t_list *x);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

#endif

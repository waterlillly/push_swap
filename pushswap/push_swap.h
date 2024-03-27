/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:11:59 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/27 01:30:33 by lbaumeis         ###   ########.fr       */
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
int		ft_max(t_list *s);
int		next_min(t_list *s, int repeat, int min);
int		ft_min(t_list *s, int repeat);
int		ft_mid(int ac, t_list *s);
void	make_b_three(t_list *a, t_list *b);
void	sort(t_list *a, int elements);
void	sort_three_a(t_list *stack);
void	sort_three_b(t_list *stack);
void	sort_three(t_list *stack);

/*check_ups.c*/
void	ft_free(t_list *s);
void	msg(int nbr);
int		arr_len(char **arr);
int		check_sort(t_list *stack);
char	**get_input(int ac, char **av);
char	**get_split_input(char **av);
int		check_doubles(char **arr);
int		presorted(char **arr);
char	**check_input(int ac, char **av);

/*creations.c*/
t_list	*add_node(t_list *stack, int value);
t_list	*stack(t_list *stack, char **input, int elements);

/*operations.c*/
void	swap(t_list *s);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	push(t_list *dst, t_list *src);
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	rot(t_list *s);
void	rev_rot(t_list *s);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

#endif
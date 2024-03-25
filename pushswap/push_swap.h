/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:11:59 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/25 21:17:03 by lbaumeis         ###   ########.fr       */
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
//void	dd_sort(t_list *stack_a, t_list *stack_b);
int		ft_max(t_list *s);
int		next_min(t_list *s, int repeat, int min);
int		ft_min(t_list *s, int repeat);
int		ft_mid(int ac, t_list *s);
void	make_b_three(t_list *a, t_list *b);
t_list	*sort(t_list *a, int elements);
int		sort_three_a(t_list *stack);
int		sort_three_b(t_list *stack);
int		sort_three(t_list *stack);

/*check_ups.c*/
void	ft_free(t_list *s);
void	msg(int nbr);
int		arr_len(int **arr);
int		check_sort(t_list *stack);
int		**get_input(int ac, char **av);
int		**get_split_input(int ac, char **av);
int		**convert_check(char **s);
int		check_doubles(int **arr);
int		presorted(int **arr);
int		**check_input(int ac, char **av);

/*creations.c*/
t_list	*add_node(t_list *stack, int value);
t_list	*stack(t_list *stack, int **input, int elements);
//char	**get_input(int ac, char **av);
//char	**two(int ac, char **av, char **input);
//char	**one(char **av, char **input);

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
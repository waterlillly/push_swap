/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:22:12 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/21 19:40:06 by lbaumeis         ###   ########.fr       */
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
int		sort_three(t_list *stack);
int		ft_max(t_list *a);
int		next_min(t_list *a, int repeat, int min);
int		ft_min(t_list *a, int repeat);
int		ft_mid(int ac, t_list *a);

/*check_ups.c*/
void	ft_free(t_list *s);
void	msg(int nbr);
int		check_doubles(int ac, char **av);
int		check_sort(t_list *stack);
int		check_input(int ac, char **av);
int 	is_sorted(int ac, char **av);

/*creations.c*/
void	add_head_node(t_list *s, t_list *node, char id);
void	add_tail_node(t_list *s, t_list *node);
void	insert_node(t_list *s, t_list *node);
t_list	*add_node(t_list *stack, int value);
t_list	*fill_stack(t_list *stack, char **input);
t_list	*stack(int	ac, char **av);
char	**ft_split(char const *s, char c);
int	ft_countstrs(char const *s, char c);
int	ft_place(char const *s, char c, int last_pos);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int ft_strlen(const char *str);

/*operations.c*/
void	swap(t_list *stack);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	push(t_list *dst, t_list *src);
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	rot(t_list *stack);
void	rev_rot(t_list *stack);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

#endif

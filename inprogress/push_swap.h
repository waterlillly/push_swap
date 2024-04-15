/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:35 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/15 13:28:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>




// typedef struct s_list t_list;

// typedef struct s_list
// {
// 	int 	data;
// 	t_list	*next;
// 	t_list	*prev;
// } 				t_list;

typedef struct s_list {
	int data;
	struct s_list * next;
	struct s_list * prev;
	
} t_list;

/*MAIN+ETC*/
//int		ft_find(char *str, int c);
//int		valid_arg(char **av);
//int		main(int ac, char **av);

/*PUSH SWAP->INPUT*/
t_list	*create_node(int data);
void	add_node(t_list **stack, t_list *new_node);
void	input_args(int ac, char **av, t_list **stack_a);
void	input_split(char **av, t_list **stack_a);
void	parse_arguments(int ac, char **av, t_list **stack);
int		make_b_three(t_list **stack_a, t_list **stack_b);
int		sort(t_list **stack_a, t_list **stack_b, int counter);
int		sort_three(t_list **stack);
int		sort_three_b(t_list **stack);
int		sort_three_a(t_list **stack);


/*CONTROL*/
void	ft_free(char **s);
void	ft_free_list(t_list **stack);
int		presorted(char **arr, int x);
int		valid(char *str);
int		stack_size(t_list **stack);
int		sort_stack(t_list **stack_a, t_list **stack_b);//chat gpt shit, platzhalter
int		find_min(t_list **stack);
int		find_max(t_list **stack);
int		is_sorted(t_list **stack);

t_list * get_last_Node(t_list **stack);

/*PUSH SWAP OPERATIONS*/
void	swap(t_list **stack);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
void	push(t_list **src_stack, t_list **dst_stack);
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
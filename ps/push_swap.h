/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:35 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/10 01:26:41 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_list t_list;

typedef struct s_list
{
	int 	data;
	t_list	*next;
	t_list	*prev;
} 				t_list;

/*MAIN*/
int		main(int ac, char **av);

/*PUSH SWAP->INPUT*/
t_list	**fill_stack_a(int ac, char **av);
void	print_stack(t_list **stack);
int		is_valid(char *str);
void	parse_and_fill(t_list **stack_a, int ac, char **av);

/*SORTING*/
int		sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_numbers(t_list **stack_a, t_list **stack_b);
int		sort_five(t_list **stack_a, t_list **stack_b);
int		sort_three_a(t_list **stack);
int		sort_three_b(t_list **stack);
int		sort_three(t_list **stack);

/*STACK*/
void	add_node(t_list **stack, int value);
void	push(t_list **src, t_list **dst);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

/*CONTROL*/
int		stack_size(t_list **stack);
int		find_min(t_list **stack);
int		find_max(t_list **stack);
int		is_sorted(t_list **stack);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:46 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/03/03 04:19:47 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list	t_list;

typedef struct s_list
{
	int	key;
	int		data;
	t_list	*next;
	t_list	*prev;
}			t_list;

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

void	*dll(t_list *start, int data)
{
	t_list	*cur;
	t_list	*head;
	t_list	*tail;

	cur = start;
	head = start;
	tail = 0;
	head->key = 1;
	while (cur != 0 && cur->next != 0)
	{
		cur = cur->next;
		if (cur->next == 0)
		{
			tail->prev = cur;
			tail->next = head;
			tail->data = NULL;
			tail->key = 2;
		}
		else
			cur->key = 0;
	}
	head->prev = tail;
	head->prev->key = 2;
	head->next->key = 0;
	head->key = 1;
	cur = head;
	head->next = cur->next;
}

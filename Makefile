# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 01:06:37 by lbaumeis          #+#    #+#              #
#    Updated: 2025/02/03 14:12:31 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIB_FLAGS = -L. -lft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = src/stack.c src/rotate.c src/rotate_both.c src/update.c src/update_a.c src/update_b.c
CFILES += src/sorting.c src/sort_five.c src/sort_three.c src/find.c src/check_sort.c src/check_stack.c
CFILES += src/swap.c src/push.c src/rot.c src/rev_rot.c src/rotate_cheapest.c src/main.c

OFILES = $(CFILES:.c=.o)
P_NAME = push_swap

all: $(P_NAME)

$(P_NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_FLAGS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(P_NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re
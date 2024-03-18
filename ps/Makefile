# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:23:35 by lbaumeis          #+#    #+#              #
#    Updated: 2024/03/18 18:09:52 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIB_FLAGS = -L. -lft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = push_swap.c operations.c creations.c check_ups.c main.c
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

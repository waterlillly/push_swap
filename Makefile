# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 01:06:37 by lbaumeis          #+#    #+#              #
#    Updated: 2024/03/03 10:24:08 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = push_swap_utils.c push_swap.c
OFILES = $(CFILES:.c=.o)
P_NAME = push_swap

LIB_DIR = ~/push_swap/libft
LIB_CFILES = $(wildcard $(LIB_DIR)/*.c)
LIB_OFILES = $(LIB_CFILES:.c=.o)
LIB_NAME = libft.a

all: $(P_NAME)

$(LIB_NAME): $(LIB_OFILES)
	ar rcs $@ $^

$(P_NAME): $(OFILES) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $^ -L. -lft

$(LIB_OFILES): %.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES) $(LIB_OFILES)

fclean: clean
	rm -f $(LIB_NAME) $(P_NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re

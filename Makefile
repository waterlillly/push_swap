CC = cc
CFLAGS = -Wall -Werror -Wextra -g
P_NAME = push_swap

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

SRCS =	srcs/stack.c \
		srcs/rotate.c \
		srcs/rotate_both.c \
		srcs/update.c \
		srcs/update_a.c \
		srcs/update_b.c \
		srcs/sorting.c \
		srcs/sort_five.c \
		srcs/sort_three.c \
		srcs/find.c \
		srcs/check_sort.c \
		srcs/check_stack.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rot.c \
		srcs/rev_rot.c \
		srcs/rotate_cheapest.c \
		srcs/main.c

OBJ = $(SRCS:.c=.o)

all: $(P_NAME)

$(P_NAME): $(OBJ)
	make -C ./libft all
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

clean:
	make -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(P_NAME)

re: fclean all

.PHONY: all clean fclean re

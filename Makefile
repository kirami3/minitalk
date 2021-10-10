NAME = server
NAME2 = client
NAME_BONUS = server_bonus
NAME2_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = server.c
SRCS2 = client.c
SRCS_BONUS = server_bonus.c
SRCS2_BONUS = client_bonus.c


OBJS		= ${SRCS:.c=.o}
OBJS2		= ${SRCS2:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}
OBJS2_BONUS		= ${SRCS2_BONUS:.c=.o}

all:	$(NAME) $(NAME2)

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) -Llibft -lft $(OBJS) -o $(NAME)

$(NAME2): $(OBJS2)

		$(CC)  $(CFLAGS) -Llibft -lft $(OBJS2) -o $(NAME2)

bonus: $(NAME_BONUS) $(NAME2_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
		make -C libft
		$(CC)  $(CFLAGS) -Llibft -lft $(OBJS_BONUS) -o $(NAME_BONUS)

$(NAME2_BONUS): $(OBJS2_BONUS)

		$(CC) $(CFLAGS) -Llibft -lft $(OBJS2_BONUS) -o $(NAME2_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS2) $(OBJS_BONUS) $(OBJS2_BONUS)
	make clean -C ./libft

fclean:	clean
	$(RM) $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)
	make fclean -C ./libft

re:		fclean all


.PHONY: all clean fclean re
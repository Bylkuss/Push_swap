NAME = push_swap
BONUS_NAME = checker
LIBFT = includes/libft/libft.a
LIBFT_PATH = includes/libft



MAKE_LIB = cd ./includes/libft && make -s



SRCS_FILES = srcs/main.c srcs/utils.c srcs/checks.c srcs/push_swap.c \
			srcs/moves.c srcs/logs.c srcs/sort_five.c srcs/utils_big_algo.c\
			srcs/big_algo.c
BONUS_SRCS_FILES = srcs/checker.c srcs/utils.c srcs/checks.c srcs/push_swap.c \
			srcs/moves.c srcs/logs.c srcs/sort_five.c srcs/utils_big_algo.c\
			srcs/big_algo.c



CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf


OBJS = $(SRCS_FILES:.c=.o)
BONUS_OBJS = $(BONUS_SRCS_FILES:.c=.o)


all: $(NAME)
bonus: $(BONUS_NAME)


$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)




clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_PATH) clean
fclean: clean
	@$(RM)  -rf $(NAME) $(BONUS_NAME) $(LIBFT)
re:		fclean all

.PHONY: all bonus clean libft fclean re

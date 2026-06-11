NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRCS = \
	utils/algorithm_genral.c \
	utils/cordanting_stack.c \
	utils/create_stack.c \
	utils/display_bench.c \
	utils/ft_split.c \
	utils/handel_input.c \
	utils/handel_option.c \
	utils/join_args.c \
	utils/main_utils.c \
	utils/print_utils.c \
	utils/stack_opration.c \
	sort/ft_adaptive.c \
	sort/ft_complex.c \
	sort/ft_radix_utils.c \
	sort/ft_meduim.c \
	sort/ft_simple.c

SRCS = utils/main.c $(COMMON_SRCS)
BONUS_SRCS = bonus/checker.c bonus/get_next_line.c $(COMMON_SRCS)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

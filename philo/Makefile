CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -g

NAME = philo

SRC = philosopher.c init_args.c ft_atoi.c create_the_list.c \
	linked_list/add_node.c routine.c calculate_time.c  globales.c \
	routine_utils.c print.c parsing.c monitor.c garbage_collector/ft_maloc.c\

HEADER = philosopher.h

all: $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

fclean :
	$(RM) $(NAME)

re: fclean all
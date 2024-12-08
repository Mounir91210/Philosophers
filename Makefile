SRCS = main.c utils.c check_arg.c init_table.c routine.c mutex.c print_mutex.c \
		routine_forone.c check_death.c time_and_sleep.c
CC = cc -Wall -Werror -Wextra -g3
NAME =	philo
OBJS =	$(SRCS:.c=.o)

all :$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "philo done !"

%.o : %.c
	@$(CC) -c $< -o $@
	@echo "compiling: $<"

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
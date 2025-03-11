SRCS = main.c utils.c check_arg.c init_table.c routine.c mutex.c print_mutex.c \
		routine_forone.c check_death.c time_and_sleep.c
CC = cc -Wall -Werror -Wextra -g3
NAME =	philo

OBJS_DIR = .objets/

SRCS_DIR = ./

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

DIR_DUP = mkdir -p $(@D)

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "philo done !"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(DIR_DUP)
	@$(CC) -c $< -o $@
	@echo "compiling: $<"

clean :
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
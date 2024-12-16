/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:50 by modavid           #+#    #+#             */
/*   Updated: 2024/12/16 20:02:54 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_philo
{
	struct s_table	*table;
	int				index;
	long			last_eat;
	long			counter_eat;
	pthread_mutex_t	counter_eat_mutex;
	pthread_mutex_t	fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	eat;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
	int				ac;
	long			each_eat;
	long			t_to_die;
	long			philo_number;
	long			t_to_eat;
	long			t_to_sleep;
	long			time;
	bool			dead;
}	t_table;

long	ft_atoi_long(const char *str);
int		init_table(t_table *table, char **av, int ac);
void	*routine(void *param);
int		mutex_print(t_philo *philo, int flag);
int		mutex_print2(t_philo *philo, int flag);
void	lock_mutex(t_philo *philo);
void	unlock_mutex(t_philo *philo);
void	create_pthread(t_table *table);
int		check_arg(t_table *table, char **av);
long	real_time_in_ms(void);
long	get_time_in_ms(t_philo *philo);
void	mutex_destroy(t_table *table);
long	check_lasteat_mutex(t_philo *philo);
int		ft_usleep(t_philo *philo, int time);
int		check_death(t_table *table);
void	hardcode_forone(t_table *table);
int		ft_isdigit(int c);
void	monitor(t_table *table);
int		check_death(t_table *table);
void	counter_eat_mutex(t_philo *philo);
int		check_each_eat(t_philo *philo);

#endif
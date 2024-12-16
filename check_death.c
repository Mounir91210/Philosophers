/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:33:05 by modavid           #+#    #+#             */
/*   Updated: 2024/12/11 10:40:12 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_table *table)
{
	pthread_mutex_lock(&table->dead_mutex);
	if (table->dead == true)
	{
		pthread_mutex_unlock(&table->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->dead_mutex);
	return (0);
}

long	check_eat_mutex(t_philo *philo)
{
	long	i;
	
	pthread_mutex_lock(&philo->counter_eat_mutex);
	i = philo->counter_eat;
	pthread_mutex_unlock(&philo->counter_eat_mutex);
	return (i);
}

int	check_each_eat(t_philo *philo)
{
	int	i;
	
	i = -1;
	while (++i < philo->table->philo_number)
	{
		if (check_eat_mutex(philo) != philo->table->each_eat)
			return (1);
	}
	return (0);
}

void	monitor(t_table *table)
{
	t_philo	*philo;
	int		i;
	long	time;

	philo = table->philo;
	while (1)
	{
		i = -1;
		while (++i < table->philo_number)
		{
			time = get_time_in_ms(philo);
			if (time - check_lasteat_mutex(&philo[i]) > table->t_to_die)
			{
				pthread_mutex_lock(&table->print);
				pthread_mutex_lock(&table->dead_mutex);
				table->dead = true;
				printf("%-5ld %d died\n", time, philo->index + 1);
				pthread_mutex_unlock(&table->dead_mutex);
				pthread_mutex_unlock(&table->print);
				return ;
			}
			if (check_each_eat(philo) == 0)
				return ;	
			usleep(50);
		}
	}
}

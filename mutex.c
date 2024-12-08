/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:20:54 by modavid           #+#    #+#             */
/*   Updated: 2024/12/06 00:25:57 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_mutex(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		mutex_print(philo, FORK);
		pthread_mutex_lock(philo->r_fork);
		mutex_print(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		mutex_print(philo, FORK);
		pthread_mutex_lock(&philo->fork);
		mutex_print(philo, FORK);
	}
}

void	unlock_mutex(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

long	check_lasteat_mutex(t_philo *philo)
{
	long	i;

	pthread_mutex_lock(&philo->eat);
	i = philo->last_eat;
	pthread_mutex_unlock(&philo->eat);
	return (i);
}

void	mutex_destroy(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_number)
		pthread_mutex_destroy(&table->philo[i].fork);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->dead_mutex);
	pthread_mutex_destroy(&table->philo->eat);
}

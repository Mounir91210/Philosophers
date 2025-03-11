/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:17:42 by modavid           #+#    #+#             */
/*   Updated: 2025/03/11 15:26:17 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (mutex_print2(philo, THINK) == 1)
		return (1);
	if (philo->table->philo_number % 2 != 0 && philo->table->t_to_die
		> philo->table->t_to_eat + philo->table->t_to_sleep)
	{
		if (ft_usleep(philo, (philo->table->t_to_die - philo->table->t_to_eat
					- philo->table->t_to_sleep) * 9 / 10) == 1)
			return (1);
	}
	return (0);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->table->ac == 6 && philo->table->each_eat == philo->counter_eat)
			return (NULL);
	if (mutex_print2(philo, THINK) == 1)
		return (NULL);
	while (1)
	{
		lock_mutex(philo);
		pthread_mutex_lock(&philo->eat);
		philo->last_eat = get_time_in_ms(philo);
		pthread_mutex_unlock(&philo->eat);
		if (mutex_print(philo, EAT) == 1)
			return (unlock_mutex(philo), NULL);
		if (ft_usleep(philo, philo->table->t_to_eat) == 1)
			return (unlock_mutex(philo), NULL);
		counter_eat_mutex(philo);
		unlock_mutex(philo);
		if (philo->table->ac == 6 && philo->table->each_eat == philo->counter_eat)
			return (NULL);
		if (mutex_print(philo, SLEEP) == 1)
			return (NULL);
		if (ft_usleep(philo, philo->table->t_to_sleep) == 1
			|| ft_think(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	pthread_while(t_table *table)
{
	int	i;

	i = 0;
	while (++i < table->philo_number)
	{
		table->philo[i].r_fork = &table->philo[(i + 1)
			% table->philo_number].fork;
		if (pthread_create(&table->philo[i].thread, NULL,
				&routine, &table->philo[i]) != 0)
			return (1);
		++i;
	}
	i = -1;
	while (++i < table->philo_number)
	{
		table->philo[i].r_fork = &table->philo[(i + 1)
			% table->philo_number].fork;
		if (pthread_create(&table->philo[i].thread, NULL,
				&routine, &table->philo[i]) != 0)
			return (1);
		++i;
	}
	return (0);
}

void	create_pthread(t_table *table)
{
	int	i;

	i = 0;
	table->time = get_time_in_ms(table->philo);
	if (pthread_while(table) == 1)
		return ;
	monitor(table);
	while (i < table->philo_number)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:25:02 by modavid           #+#    #+#             */
/*   Updated: 2024/12/06 00:25:39 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_printf_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	if (check_death(philo->table) == 1)
		return (pthread_mutex_unlock(&philo->table->print), 1);
	return (0);
}

int	mutex_print(t_philo *philo, int flag)
{
	if (flag == FORK)
	{
		if (lock_printf_mutex(philo) == 1)
			return (1);
		printf("%-5ld %d has taken a fork\n",
			(get_time_in_ms(philo)), philo->index + 1);
		pthread_mutex_unlock(&philo->table->print);
	}
	if (flag == EAT)
	{
		if (lock_printf_mutex(philo) == 1)
			return (1);
		printf("%-5ld %d is eating\n",
			(get_time_in_ms(philo)), philo->index + 1);
		pthread_mutex_unlock(&philo->table->print);
	}
	if (flag == SLEEP)
	{
		if (lock_printf_mutex(philo) == 1)
			return (1);
		printf("%-5ld %d is sleeping\n",
			(get_time_in_ms(philo)), philo->index + 1);
		pthread_mutex_unlock(&philo->table->print);
	}
	return (0);
}

int	mutex_print2(t_philo *philo, int flag)
{
	if (flag == THINK)
	{
		if (lock_printf_mutex(philo) == 1)
			return (1);
		printf("%-5ld %d is thinking\n",
			(get_time_in_ms(philo)), philo->index + 1);
		pthread_mutex_unlock(&philo->table->print);
	}
	if (flag == DIE)
	{
		if (lock_printf_mutex(philo) == 1)
			return (1);
		printf("%-5ld %d died\n",
			(get_time_in_ms(philo)), philo->index + 1);
		pthread_mutex_unlock(&philo->table->print);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:35:59 by modavid           #+#    #+#             */
/*   Updated: 2024/12/16 21:20:44 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - philo->table->time);
}

long	real_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

int	ft_usleep(t_philo *philo, int time)
{
	int	start;

	start = get_time_in_ms(philo);
	while (start > (get_time_in_ms(philo) - time))
	{
		if (check_death(philo->table) == 1)
			return (1);
		if (philo->table->ac == 6)
		{
			if (check_each_eat(philo) == 0)
				return (1);
		}
		usleep(10);
	}
	return (0);
}

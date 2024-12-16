/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_forone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:28:40 by modavid           #+#    #+#             */
/*   Updated: 2024/12/16 21:19:44 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_forone(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->fork);
	printf("%-5ld %d has taken a fork\n", philo->table->time, philo->index + 1);
	ft_usleep(philo, philo->table->t_to_die);
	printf("%-5ld %d died\n", philo->table->time, philo->index + 1);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

void	hardcode_forone(t_table *table)
{
	if (pthread_create(&table->philo[0].thread, NULL, &routine_forone,
			&table->philo[0]) != 0)
		return ;
	pthread_join(table->philo[0].thread, NULL);
}

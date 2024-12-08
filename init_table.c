/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:16:37 by modavid           #+#    #+#             */
/*   Updated: 2024/12/05 23:57:40 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, char **av)
{
	int	i;

	table->philo_number = ft_atoi_long(av[1]);
	table->philo = malloc(sizeof(t_philo) * table->philo_number);
	if (!table->philo)
		return (write(2, "Error\n", 6), 1);
	memset(table->philo, 0, sizeof(t_philo) * table->philo_number);
	i = -1;
	table->t_to_die = ft_atoi_long(av[2]);
	table->t_to_eat = ft_atoi_long(av[3]);
	table->t_to_sleep = ft_atoi_long(av[4]);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->philo->eat, NULL);
	while (++i < table->philo_number)
	{
		table->philo[i].index = i;
		table->philo[i].table = table;
		table->philo[i].last_eat = 0;
		pthread_mutex_init(&table->philo[i].fork, NULL);
	}
	return (0);
}

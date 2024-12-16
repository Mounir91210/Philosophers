/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:17 by modavid           #+#    #+#             */
/*   Updated: 2024/12/11 10:17:20 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac < 5 || ac > 6)
		return (1);
	memset(&table, 0, sizeof(t_table));
	if (init_table(&table, av, ac) == 1)
		return (1);
	if (check_arg(&table, av) == 1)
		return (free(table.philo), 1);
	if (table.philo_number > 1)
		create_pthread(&table);
	else
		hardcode_forone(&table);
	mutex_destroy(&table);
	free(table.philo);
	return (0);
}

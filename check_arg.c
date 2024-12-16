/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:35 by modavid           #+#    #+#             */
/*   Updated: 2024/12/11 10:42:14 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_arg(t_table *table, char **av)
{
	if (ft_isnum(av[1]) == 1 || ft_isnum(av[2]) == 1 || ft_isnum(av[3]) == 1
		|| ft_isnum(av[4]) == 1)
		return (write(2, "Error Parsing\n", 14), 1);
	if (table->philo_number > 200 || table->philo_number < 1)
		return (write(2, "Error Parsing\n", 14), 1);
	if ((table->t_to_die > 2147483647 || table->t_to_die < 0)
		|| (table->t_to_eat > 2147483647 || table->t_to_eat < 0)
		|| (table->t_to_sleep > 2147483647 || table->t_to_die < 0))
		return (write(2, "Error Parsing\n", 14), 1);
	if (table->t_to_die > 2147483647 || table->t_to_eat > 2147483647
		|| table->t_to_sleep > 2147483647)
		return (write(2, "Error Parsing\n", 14), 1);
	return (0);
}

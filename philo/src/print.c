/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:22:00 by ncampbel          #+#    #+#             */
/*   Updated: 2024/08/16 18:29:02 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *message, t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(&philo->table->print_message);
	if (philo->table->all_alive == true)
	{
		printf("%ld %d %s\n", time - philo->table->start, philo->name, message);
	}
	pthread_mutex_unlock(&philo->table->print_message);
}

void	death_eaten(t_table *table, int name)
{
	unsigned int	i;

	pthread_mutex_lock(&table->print_message);
	printf("%ld %d died\n", gettimeofday_ms() - table->start,
		table->philo[name].name);
	table->all_alive = false;
	pthread_mutex_unlock(&table->philo[name].body);
	i = -1;
	while (++i < table->n_philo)
	{
		pthread_mutex_lock(&table->philo[i].body);
		table->philo[i].stop = true;
		pthread_mutex_unlock(&table->philo[i].body);
	}
	pthread_mutex_unlock(&table->print_message);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:22:00 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/28 10:56:56 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


void	print_message(int	m_id, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_message);
	if (philo->table->all_alive == true)
	{
		if (m_id == 1)
			printf("%ld %d is eating\n", gettimeofday_ms() - 	philo->table->start, philo->name);
		else if (m_id == 2)
			printf("%ld %d is sleeping\n", gettimeofday_ms() - 	philo->table->start, philo->name);
		else if (m_id == 3)
			printf("%ld %d is thinking\n", gettimeofday_ms() - 	philo->table->start, philo->name);
		else if (m_id == 4)
			printf("%ld %d has taken a fork\n", gettimeofday_ms() - 	philo->table->start, philo->name);
		else if (m_id == 5)
		{
			printf("%ld %d died\n", gettimeofday_ms() - 	philo->table->start, philo->name);
			philo->table->all_alive = false;
		}
	}
	pthread_mutex_unlock(&philo->table->print_message);
}
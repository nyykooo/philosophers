/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:27:46 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/24 17:46:05 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_message);
	print_message(1, philo);
	usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->l_fork.fork);
	philo->l_fork.taken = false;
	pthread_mutex_unlock(&philo->r_fork.fork);
	philo->r_fork.taken = false;
	pthread_mutex_unlock(&philo->table->print_message);
	if (philo->amount_eat > 0)
		philo->amount_eat--;
}

void	sleeping(t_philo *philo)
{
	print_message(2, philo);
	usleep(philo->t_sleep);
	philo->is_awake = false;
}

void	thinking(t_philo *philo)
{
	print_message(3, philo);
	philo->is_awake = true;
}
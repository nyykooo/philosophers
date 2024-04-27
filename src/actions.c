/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:27:46 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/27 12:16:55 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	print_message(1, philo, 0);
	philo->t_last_meal = gettimeofday_ms();
	better_msleep(philo->t_eat);
	if (philo->amount_eat > 0)
		philo->amount_eat--;
}

void	sleeping(t_philo *philo)
{
	print_message(2, philo, 0);
	pthread_mutex_unlock(&philo->l_fork.fork);
	philo->l_fork.taken = false;
	pthread_mutex_unlock(&philo->r_fork.fork);
	philo->r_fork.taken = false;
	better_msleep(philo->t_sleep);
	philo->is_awake = false;
}

void	thinking(t_philo *philo)
{
	print_message(3, philo, 0);
	philo->is_awake = true;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:27:46 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/09 16:29:33 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	if (philo->l_fork && philo->r_fork)
	{
		pthread_mutex_lock(&philo->body);
		philo->t_last_meal = gettimeofday_ms();
		print_message("is eating", philo, philo->t_last_meal);
		if (philo->amount_eat > 0)
			philo->amount_eat--;
		if (philo->amount_eat == 0)
			philo->stop = true;
		pthread_mutex_unlock(&philo->body);
		better_msleep(philo->t_eat);
	}
	if (philo->name % 2 == 1)
	{
		if (philo->r_fork)
			pthread_mutex_unlock(&philo->r_fork->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->r_fork->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
}

void	sleeping(t_philo *philo)
{
	print_message("is sleeping", philo, gettimeofday_ms());
	better_msleep(philo->t_sleep);
	philo->is_awake = false;
}

void	thinking(t_philo *philo)
{
	print_message("is thinking", philo, gettimeofday_ms());
	better_msleep(philo->t_think);
	philo->is_awake = true;
}

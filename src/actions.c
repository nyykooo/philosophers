/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:27:46 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/02 15:09:26 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	// pthread_mutex_lock(&philo->table->print_message);
	// if (philo->table->all_alive == true)
	// {
	// 	printf("%ld %d %s\n", gettimeofday_ms() - 	philo->table->start, philo->name, "is eating");
	// }
	// pthread_mutex_unlock(&philo->table->print_message);
	philo->t_last_meal = gettimeofday_ms();
	print_message("is eating", philo, philo->t_last_meal);
	better_msleep(philo->t_eat);
	pthread_mutex_unlock(&philo->l_fork->fork);
	philo->l_fork->taken = false;
	pthread_mutex_unlock(&philo->r_fork->fork);
	philo->r_fork->taken = false;
	if (philo->amount_eat > 0)
		philo->amount_eat--;
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
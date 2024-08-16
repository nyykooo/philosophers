/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:07:27 by ncampbel          #+#    #+#             */
/*   Updated: 2024/08/16 18:29:32 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	gettimeofday_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

void	better_msleep(unsigned long delay_ms, t_philo *philo)
{
	unsigned long	deadline;

	deadline = gettimeofday_ms() + delay_ms;
	while (gettimeofday_ms() <= deadline)
	{
		pthread_mutex_lock(&philo->body);
		if (philo->stop == true)
		{
			pthread_mutex_unlock(&philo->body);
			return ;
		}
		pthread_mutex_unlock(&philo->body);
		usleep(500);
	}
}

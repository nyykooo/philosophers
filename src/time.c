/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:07:27 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/26 15:23:40 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	gettimeofday_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec)*1000 + (time.tv_usec)/1000);
}

void	better_msleep(long delay_ms)
{
	long	time_ms;
	long	deadline;

	time_ms = gettimeofday_ms();
	deadline = time_ms + delay_ms;
	while (gettimeofday_ms() < deadline)
		usleep(1);
}
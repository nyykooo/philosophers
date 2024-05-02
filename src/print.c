/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:22:00 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/02 14:52:19 by ncampbel         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:22:00 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/24 17:23:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(int	m_id, t_philo *philo)
{
	if (m_id == 1)
		printf("philo %d is eating\n", philo->name);
	else if (m_id == 2)
		printf("philo %d is sleeping\n", philo->name);
	else if (m_id == 3)
		printf("philo %d is thinking\n", philo->name);
}
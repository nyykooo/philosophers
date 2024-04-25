/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:03:25 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/25 15:14:17 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(char *message, t_table *table)
{
	unsigned int	i;

	i = 0;
	if (table)
	{
		if (table->philo)
			free(table->philo);
		while (i < table->n_philo)
			pthread_detach(table->philo[i++].mind);
	}
	if (message)
	{
		write(2, message, ft_strlen(message));
		exit(EXIT_FAILURE);
	}
}
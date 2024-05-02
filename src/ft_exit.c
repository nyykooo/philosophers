/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:03:25 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/01 13:59:04 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(char *message, t_table *table)
{
	if (table)
	{
		if (table->philo)
			free(table->philo);
		if (table->fork)
			free(table->fork);
	}
	if (message)
	{
		write(2, message, ft_strlen(message));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
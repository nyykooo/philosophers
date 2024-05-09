/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:03:25 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/08 11:51:53 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(t_table *table)
{
	if (table)
	{
		if (table->philo)
			free(table->philo);
		if (table->fork)
			free(table->fork);
	}
}
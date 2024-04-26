/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:18:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/26 17:38:00 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_fork(t_fork *fork, t_table *table, int i)
{
	fork->taken = false;
	fork->id = i + 1;
	if (pthread_mutex_init(&table->fork[i].fork, NULL) != 0)
		ft_exit("mutex (fork) error\n", table);
}

void	create_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < (int)table->n_philo)
	{
		init_fork(&table->fork[i], table, i);
		i++;
	}
}

bool	check_forks(t_philo *philo, t_fork *left, t_fork *right)
{
	if (left->taken == false && right->taken == false)
	{
		pthread_mutex_lock(&left->fork);
		left->taken = true;
		print_message(4, philo);
		pthread_mutex_lock(&right->fork);
		right->taken = true;
		print_message(4, philo);
		return (true);
	}
	else
		return (false);
}

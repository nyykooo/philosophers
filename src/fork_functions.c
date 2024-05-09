/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:18:13 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/08 15:34:36 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static bool	init_fork(t_fork *fork, t_table *table, int i)
{
	fork->id = i + 1;
	if (pthread_mutex_init(&table->fork[i].fork, NULL) != 0)
		return (false);
	return (true);
}

void	create_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < (int)table->n_philo)
	{
		if (init_fork(&table->fork[i], table, i) == false)
		{
			ft_exit(table);
			return ;
		}
		i++;
	}
}

void	check_forks(t_philo *philo, t_fork *left, t_fork *right)
{
	if (philo->name % 2 == 1)
		pthread_mutex_lock(&left->fork);
	else
		pthread_mutex_lock(&right->fork);
	print_message("has taken a fork", philo, gettimeofday_ms());
	if (philo->name % 2 == 1)
		pthread_mutex_lock(&right->fork);
	else
		pthread_mutex_lock(&left->fork);
	print_message("has taken a fork", philo, gettimeofday_ms());
}

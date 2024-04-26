/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:15:28 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/26 17:50:58 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	habits(t_philo *philo)
{
	if (philo->name % 2 == 0)
		better_msleep(philo->t_eat);
	while (1)
	{
		if ((philo->amount_eat == -1 ||
			 philo->amount_eat > 0)
			&& (check_forks(philo, &philo->l_fork, &philo->r_fork) == true))
		{
			eating(philo);
			sleeping(philo);
		}
		else if (!philo->is_awake)
			thinking(philo);
	}
}

void	*mind_hub(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;
	pthread_mutex_lock(&philo->table->may_we);
	pthread_mutex_unlock(&philo->table->may_we);
	habits(philo);
	return (NULL);
}

static void	init_philo(t_philo *philo, t_table *table, int name)
{
	philo->t_die = table->t_die;
	philo->t_sleep = table->t_sleep;
	philo->t_eat = table->t_eat;
	philo->amount_eat = table->amount_eat;
	philo->name = name;
	philo->table = table;
	philo->is_awake = true;
	philo->t_last_meal = table->start;
	philo->l_fork = table->fork[philo->name - 1];
	if ((unsigned int)philo->name == table->n_philo)
		philo->r_fork = table->fork[0];
	else
		philo->r_fork = table->fork[philo->name - 1];
}

void	create_philo(t_table *table)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_lock(&table->may_we);
	while (i < table->n_philo)
	{
		init_philo(&table->philo[i], table, i + 1);
		if (pthread_create(&table->philo[i].mind, NULL, mind_hub, 
			&table->philo[i]) != 0)
			ft_exit("", table);
		i++;
	}
	pthread_mutex_unlock(&table->may_we);
}

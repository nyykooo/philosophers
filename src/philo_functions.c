/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:15:28 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/24 17:52:49 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	habits(t_philo *philo)
{
	if (philo->name % 2 == 0)
		usleep(200);
	while (1)
	{
		if (check_forks(&philo->l_fork, &philo->r_fork) == true
			&& philo->amount_eat != 0)
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

static t_philo	init_philo(t_table *table, int name)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->t_die = table->t_die;
	philo->t_sleep = table->t_sleep;
	philo->t_eat = table->t_eat;
	philo->amount_eat = table->amount_eat;
	philo->name = name;
	philo->table = table;
	philo->is_awake = true;
	philo->l_fork = table->fork[philo->name - 1];
	if (table->n_philo > 1 && (unsigned int)philo->name == table->n_philo)
		philo->r_fork = table->fork[0];
	else if (table->n_philo > 1)
		philo->r_fork = table->fork[philo->name];
	philo->t_last_meal = 0;
	return (*philo);
}

void	create_philo(t_table *table)
{
	unsigned int	i;

	i = 1;
	table->philo = malloc(sizeof(t_philo)*table->n_philo);
	pthread_mutex_lock(&table->may_we);
	while (i <= table->n_philo)
	{
		table->philo[i] = init_philo(table, i);
		if (pthread_create(&table->philo[i].mind, NULL, mind_hub, 
			&table->philo[i]) != 0)
			write(2, "invalid input\n", 15);// ft_error("pthread create\n", table);
		usleep(100);
		i++;
	}
	pthread_mutex_unlock(&table->may_we);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:15:28 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/02 16:08:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static unsigned long get_t_think(t_table *table)
{
	unsigned long t_think;

	if (table->n_philo % 2 == 1)
		t_think = table->t_eat * 2 - table->t_sleep;
	else
		t_think = table->t_eat - table->t_sleep;
	return (t_think);
}

static void	habits(t_philo *philo)
{
	if (philo->table->n_philo % 2 == 1)
	{
		if ((unsigned int)philo->name == philo->table->n_philo)
			better_msleep(philo->t_eat * 2);
		else if (philo->name % 2 == 1)
			better_msleep(philo->t_eat);
	}
	else if (philo->name % 2 == 0)
		better_msleep(philo->t_eat);
	while (philo->alive == true && (philo->amount_eat == -1
			|| philo->amount_eat > 0))
	{
		check_forks(philo, philo->l_fork, philo->r_fork);
		eating(philo);
		if (!philo->stop)
			return ();
		sleeping(philo);
		if (sair)
			return ();
		thinking(philo);
		if (sair)
			return ();
	}
	// FAZAER MUTEX TANTO PARA O PHILO QUANTO PARA AS VARIAVEIS QUE VOU VERIFICAR EM MAIS DE UMA THREAD
	// {
	// 	if ((philo->amount_eat == -1 ||
	// 		 philo->amount_eat > 0)
	// 		&& (check_forks(philo, philo->l_fork, philo->r_fork) == true))
	// 	{
	// 		check_forks(philo, philo->l_fork, philo->r_fork)
	// 		eating(philo);
	// 		sleeping(philo);
	// 		thinking(philo);
	// 	}
	// }
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
	philo->t_think = get_t_think(table);
	philo->amount_eat = table->amount_eat;
	philo->name = name + 1;
	philo->table = table;
	philo->is_awake = true;
	philo->t_last_meal = table->start;
	philo->l_fork = &table->fork[name];
	if ((unsigned int)philo->name == table->n_philo)
		philo->r_fork = &table->fork[0];
	else
		philo->r_fork = &table->fork[name + 1];
}

void	create_philo(t_table *table)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_lock(&table->may_we);
	while (i < table->n_philo)
	{
		init_philo(&table->philo[i], table, i);
		if (pthread_create(&table->philo[i].mind, NULL, mind_hub, 
			&table->philo[i]) != 0)
			ft_exit("", table);
		i++;
	}
	pthread_mutex_unlock(&table->may_we);
}

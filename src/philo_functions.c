/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:15:28 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/25 21:32:51 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// static void	habits(t_philo *philo)
// {
// 	if (philo->name % 2 == 0)
// 		usleep(200);
// 	while (1)
// 	{
// 		if (check_forks(&philo->l_fork, &philo->r_fork) == true
// 			&& philo->amount_eat != 0)
// 		{
// 			eating(philo);
// 			sleeping(philo);
// 		}
// 		else if (!philo->is_awake)
// 			thinking(philo);
// 	}
// }

void	*mind_hub(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;
	pthread_mutex_lock(&philo->table->may_we);
	printf("philo created: %d\n", philo->name);
	pthread_mutex_unlock(&philo->table->may_we);
	// habits(philo);
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
	philo->t_last_meal = 0;
}

void	create_philo(t_table *table)
{
	unsigned int	i;

	pthread_mutex_lock(&table->may_we);
	i = 1;
	while (i <= table->n_philo)
	{
		init_philo(&table->philo[i - 1], table, i);
		if (pthread_create(&table->philo[i - 1].mind, NULL, mind_hub, 
			&table->philo[i] - 1) != 0)
			ft_exit("", table);
		usleep(100);
		i++;
	}
	pthread_mutex_unlock(&table->may_we);
}

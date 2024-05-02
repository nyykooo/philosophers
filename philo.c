/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:42:08 by ncampbel          #+#    #+#             */
/*   Updated: 2024/05/02 16:08:18 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	wait_threads(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n_philo)
		pthread_join(table->philo[i++].mind, NULL);
	ft_exit(NULL, table);
	
}

static void	check_4deaths(t_table *table)
{
	unsigned int	i;
	unsigned int	n;

	while (table->all_alive == true)
	{
		i = 0;
		n = 0;
		while (i < table->n_philo)
		{
			if (table->philo[i].amount_eat == 0)
				n++;
			if (n == table->n_philo)
				wait_threads(table);
			if((table->philo[i].amount_eat == -1 || table->philo[i].amount_eat
				> 0) && (gettimeofday_ms() - table->philo[i].t_last_meal > table->t_die))
			{
				pthread_mutex_lock(&table->print_message);
				printf("%ld %d died\n", gettimeofday_ms() - table->start, table->philo[i].name);
				table->all_alive = false;
				pthread_mutex_unlock(&table->print_message);
				wait_threads(table);
			}
			i++;
		}
	}
}

static void	init_table(t_table *table, char **av)
{
	table->n_philo = ft_atoi(av[1]);
	table->t_die = ft_atol(av[2]);
	table->t_eat = ft_atol(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	table->amount_eat = -1;
	table->all_alive = true;
	table->start = gettimeofday_ms();
	if (av[5])
		table->amount_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&table->may_we, NULL) != 0)
		ft_exit("mutex 'may_we' error\n", table);
	if (pthread_mutex_init(&table->print_message, NULL) != 0)
		ft_exit("mutex 'print_message' error\n", table);
	table->philo = (t_philo *)malloc(sizeof(t_philo)*table->n_philo);
	if (!table->philo)
		ft_exit("malloc philo\n", table);
	table->fork = (t_fork *)malloc(sizeof(t_fork)*table->n_philo);
	if (!table->fork)
		ft_exit("malloc fork\n", table);
	create_fork(table);
	create_philo(table);
}

static void	parse_input(int ac)
{
	if (ac < 5)
		ft_exit("invalid input\n", NULL);
	return ;
}

int	main(int ac, char **av)
{
	static t_table	table;
	
	parse_input(ac);
	init_table(&table, av);
	check_4deaths(&table);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:42:08 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/25 15:43:21 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_table(char **av)
{
	t_table *table;
	
	table = (t_table *)malloc(sizeof(t_table));
	table->n_philo = ft_atoi(av[1]);
	table->t_die = ft_atol(av[2]);
	table->t_eat = ft_atol(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	table->amount_eat = -1;
	if (av[5])
		table->amount_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&table->may_we, NULL) != 0)
		ft_exit("mutex 'may_we' error\n", table);
	if (pthread_mutex_init(&table->print_message, NULL) != 0)
		ft_exit("mutex 'print_message' error\n", table);
	table->philo = (t_philo *)malloc(sizeof(t_philo)*table->n_philo);
	if (!table->philo)
		ft_exit("malloc philo\n", table);
	create_philo(table);
	gettimeofday(&table->start, NULL);
}

static void	parse_input(int ac)
{
	if (ac < 5)
		ft_exit("invalid input\n", NULL);
	return ;
}

int	main(int ac, char **av)
{
	parse_input(ac);
	init_table(av);
	return (0);
}
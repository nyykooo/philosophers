/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:42:08 by ncampbel          #+#    #+#             */
/*   Updated: 2024/04/24 17:48:22 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_table(char **av)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	table->n_philo = ft_atoi(av[1]);
	table->t_die = ft_atol(av[2]);
	table->t_eat = ft_atol(av[3]);
	table->t_sleep = ft_atol(av[4]);
	table->amount_eat = -1;
	if (pthread_mutex_init(&table->may_we, NULL) != 0)
		write(2, "invalid input\n", 15);//ft_error("pthread create\n", table);
	if (pthread_mutex_init(&table->print_message, NULL) != 0)
		write(2, "invalid input\n", 15);//ft_error("pthread create\n", table);
	if (av[5])
		table->amount_eat = ft_atoi(av[5]);
	create_fork(table);
	create_philo(table);
	gettimeofday(&table->start, NULL);
	// while (1)
	// {
		
	// }
}

static void parse_input(int ac, char **av)
{
	if (ac < 5)
		write(2, "invalid input\n", 15);
	else
		init_table(av);
}

int	main(int ac, char **av)
{
	parse_input(ac, av);
	usleep(1000);
}